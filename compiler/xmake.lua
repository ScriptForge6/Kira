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
target(COM_NAME)
	set_kind("binary")
	add_cxxflags({
        "/permissive-",
        "/Zc:preprocessor",
        "/Zc:templateScope"
    }, {tools = {"cl"}})
    
    add_extrafiles(LANG_DIR)
    
    add_packages("nlohmann_json")

    add_defines("LANG=" .. "\"" .. LANG .. "\"")

    add_includedirs(COM_DIR)
    add_includedirs(DETAIL_DIR)
    
    add_files(path.join(COM_DIR, "*.cpp"))
    add_files(path.join(DETAIL_DIR, "*.cpp"))
    add_headerfiles(path.join(COM_DIR, "*.hpp"))

    add_extrafiles(path.join(LANG_DIR, "*.json"))
target_end()