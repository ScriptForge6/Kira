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
 * @file Msg.hpp
 * @brief 定义了一个消息容器类
 * @author Scriptforge
 * @date 2026/10/17
 */

#pragma once
#ifndef KIRA_COMPILER_MSG_HPP
#define KIRA_COMPILER_MSG_HPP

#include "MsgApi.hpp"

#include <chrono>
#include <cstdint>
#include <memory>

/**
 * @brief 定义的消息等级
*/
enum class KIRA_API_MSG InfoLevel : uint8_t {
	Unknown = 0,
	Debug = 1,
	Info = 2,
	Warning = 3,
	Error = 4,
	Critial = 5
};

/**
 * @brief 定义消息容器
 * @note 非线程安全
*/
class KIRA_API_MSG Msg {
private:
	using Clock = std::chrono::system_clock;
	using TimePoint = Clock::time_point;
public:
	Msg() = delete;
	/**
	 * @brief Msg 的构造函数
	 * @param[in] msg       消息核心内容
	 * @param[in] infoLevel 消息等级
	 * @param[in] tp        日志时间
	 */
	Msg(
		const char* msg,
		const InfoLevel infoLevel = InfoLevel::Info,
		const std::optional<TimePoint> tp = std::nullopt/* = Clock::now()*/
	) noexcept;
private:
	std::exception_ptr m_lazyLoadExceptPtr = nullptr;
	const char* m_msg = nullptr;
	InfoLevel m_infoLevel = InfoLevel::Unknown;
	TimePoint m_tp;
};

#endif