# CMakeList.txt : CMake project for NLang, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("NLang")

# Add source to this project's executable.
file(GLOB NLang_src CONFIGURE_DEPENDS "*.cpp")

add_executable (NLang ${NLang_src})

target_precompile_headers(NLang PUBLIC "pch.hpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NLang PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
