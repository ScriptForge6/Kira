// Copyright 2026 Scriptforge
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//     http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file ExePath.hpp
 * @brief 获取可执行文件位置或地址
 * @brief 获取可执行文件位置或地址
 * @author Scriptforge
 * @date 2026/10/11
 */

#pragma once
#include <filesystem>
#include <string>
#include <system_error>

#if defined(_WIN32)
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#include <vector>
#elif defined(__linux__)
#include <unistd.h>
#elif defined(__FreeBSD__)
#include <sys/types.h>
#include <sys/sysctl.h>
#else
#error "Unsupported platform"
#endif

/**
 * @brief 获取可执行文件地址
 * @return 返回可执行文件地址
 * @retval std::nullopt 出现错误
*/
inline std::optional<std::filesystem::path> getExePath() {
    namespace fs = std::filesystem;
    fs::path result;

#if defined(_WIN32)
    std::wstring buf(MAX_PATH, L'\0');
    for (;;) {
        DWORD n = GetModuleFileNameW(nullptr, buf.data(), static_cast<DWORD>(buf.size()));
        if (n == 0) return std::nullopt;
        if (n < buf.size()) { buf.resize(n); break; }   // 成功
        if (buf.size() > 32768) return std::nullopt;    // 防止无限扩容
        buf.resize(buf.size() * 2);                     // 被截断，重试
    }
    result = buf;

#elif defined(__APPLE__)
    uint32_t size = 0;
    _NSGetExecutablePath(nullptr, &size);               // 先问需要多大
    std::vector<char> buf(size);
    if (_NSGetExecutablePath(buf.data(), &size) != 0) return std::nullopt;
    result = buf.data();

#elif defined(__linux__)
    std::string buf(256, '\0');
    for (;;) {
        ssize_t n = readlink("/proc/self/exe", buf.data(), buf.size());
        if (n < 0) return std::nullopt;
        if (static_cast<size_t>(n) < buf.size()) { buf.resize(n); break; }
        if (buf.size() > 65536) return std::nullopt;
        buf.resize(buf.size() * 2);                     // readlink 截断时不报错，要自己判断
    }
    result = buf;

#elif defined(__FreeBSD__)
    int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
    size_t len = 0;
    if (sysctl(mib, 4, nullptr, &len, nullptr, 0) != 0 || len == 0) return std::nullopt;
    std::string buf(len, '\0');
    if (sysctl(mib, 4, buf.data(), &len, nullptr, 0) != 0) return std::nullopt;
    result = buf.c_str();
#endif

    // 规范化：解析符号链接、去掉 ../，用 error_code 版本不抛异常
    std::error_code ec;
    fs::path canon = fs::canonical(result, ec);
    return ec ? result : canon;
}

/**
 * @brief 获取可执行文件位置
 * @return 返回可执行文件位置
 * @retval std::nullopt 出现错误
*/
inline std::optional<std::filesystem::path> getExeDir() {
    auto p = getExePath();
    if (!p) return std::nullopt;
    return p->parent_path();
}