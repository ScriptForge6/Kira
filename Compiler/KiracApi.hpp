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
 * @file KiracApi.hpp
 * @brief 定义了一些宏
 * @author Scriptforge
 * @date 2026/10/16
 */

#pragma once
#ifndef KIRACAPI_HPP
#define KIRACAPI_HPP

#if defined(_WIN32) || defined(_WIN64)
	#define KIRA_WIN 1
#elif defined(__APPLE__)
	#include <TargetConditionals.h>
	#define KIRA_APPLE 1
	#if TARGET_OS_IPHONE
		#define KIRA_IOS 1
	#else
		#define KIRA_MAC 1
	#endif
#elif defined(__linux__)
	#define KIRA_LINUX 1
#elif defined(__FreeBSD__)
	#define KIRA_FREEBSD 1
#else
	#error "Unsupported platform"
#endif


#ifndef KIRA_IMPORT_API
	#if defined(KIRA_WIN)
		#define KIRA_IMPORT_API __declspec(dllimport)
	#else
		#define KIRA_IMPORT_API
	#endif
#endif

#ifndef KIRA_EXPORT_API
	#if defined(KIRA_WIN)
		#define KIRA_EXPORT_API __declspec(dllexport)
	#else
		#define KIRA_EXPORT_API __attribute__((visibility("default")))
	#endif
#endif

#if defined(_MSVC_LANG)
	#define KIRA_CPLUSPLUS _MSVC_LANG
#elif defined(__cplusplus)
	#define KIRA_CPLUSPLUS __cplusplus
#else
	#define KIRA_CPLUSPLUS 0L
#endif

// ---- KIRA_DEPRECATED(msg):标记废弃 ----
#if KIRA_CPLUSPLUS >= 201402L
	#define KIRA_DEPRECATED(msg) [[deprecated(msg)]]
#elif defined(_MSC_VER)
	#define KIRA_DEPRECATED(msg) __declspec(deprecated(msg))
#elif defined(__GNUC__) || defined(__clang__)
	#define KIRA_DEPRECATED(msg) __attribute__((deprecated(msg)))
#else
	#define KIRA_DEPRECATED(msg)
#endif

// ---- KIRA_NODISCARD:忽略返回值时警告 ----
#if KIRA_CPLUSPLUS >= 201703L
	#define KIRA_NODISCARD [[nodiscard]]
#elif defined(__GNUC__) || defined(__clang__)
	#define KIRA_NODISCARD __attribute__((warn_unused_result))
#elif defined(_MSC_VER) && _MSC_VER >= 1700
	#include <sal.h>
	#define KIRA_NODISCARD _Check_return_
#else
	#define KIRA_NODISCARD
#endif

#endif