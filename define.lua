--[[
Copyright 2026 Scriptforge
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
]]--
SCRIPT_NAME = "Kira"
VERSION = "0.0.0"
LICENSE = "Apache License 2.0"
START_YEAR = 2026
AUTHOR = "Scriptforge"
COM_NAME = "compiler"
LANG = "lang"
DETAIL = "detail"
PROJECTDIR = os.projectdir()
COM_DIR = path.join(PROJECTDIR, COM_NAME)
COM_LUA = path.join(COM_DIR, "xmake.lua")
LANG_DIR = path.join(LIB_DIR, LANG)
DETAIL_DIR = path.join(COM_DIR, DETAIL)