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

SCRIPT_NAME = "Kirac"
VERSION = "0.0.0"
LICENSE = "Apache License 2.0"
START_YEAR = 2026
AUTHOR = "Scriptforge"
PROJECTDIR = os.projectdir()
LANG = "lang"
local TARGET_MAIN_FILE = "xmake.lua"

API_FILENAME = "KiracApi.hpp"
API_FILE = path.join(PROJECTDIR, API_FILENAME)

MAIN_NAME = "kirac"
MAIN_DIR = path.join(PROJECTDIR, "main")
MAIN_LUA = path.join(MAIN_DIR, TARGET_MAIN_FILE)

LANG_NAME = "lang"
LANG_DIR = path.join(PROJECTDIR, LANG_NAME)
LANG_LUA = path.join(LANG_DIR, TARGET_MAIN_FILE)