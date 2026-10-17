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
 * @file LangApi.hpp
 * @brief 定义了一些宏
 * @author Scriptforge
 * @date 2026/10/17
 */

#pragma once
#include <KiracApi.hpp>

#ifndef LANGAPI_HPP
#define LANGAPI_HPP

#ifndef KIRA_API_LANG
#if defined(KIRA_LANG_IMPORT) && defined(KIRA_LANG_EXPORT)
#error "Error: Only one of KIRA_LANG_IMPORT and KIRA_LANG_EXPORT may be defined"
#endif
	#if defined(KIRA_LANG_IMPORT)
		#define KIRA_API_LANG KIRA_IMPORT_API
	#elif defined(KIRA_LANG_EXPORT)
		#define KIRA_API_LANG KIRA_EXPORT_API
#else
#error "Error: Must define KIRA_LANG_IMPORT or KIRA_LANG_EXPORT"
	#endif
#endif

#endif
