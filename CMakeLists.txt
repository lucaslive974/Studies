cmake_minimum_required(VERSION 3.16)
project(CppPatterns)


if(NOT CMAKE_BUILD_TYPE)
  set(default_build_type "Debug")
  message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
  set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Chooce the build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
  "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "Studies Build Type: ${CMAKE_BUILD_TYPE}")

# Set the version for myProject
set(myProject_Version_Major 0)
set(myProject_Version_Minor 1)
set(myProject_Version_Patch 0)
set(myProject_Version_Status "-dev")
set(PROJECT_VERSION
  "${myProject_Version_Major}.${myProject_Version_Minor}.${myProject_Version_Patch}${myProject_Version_Status}"
)
message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

message(STATUS "Standard: ${CMAKE_CXX_STANDARD} Required: ${CMAKE_CXX_STANDARD_REQUIRED}")

message(STATUS "Compiler C: ${CMAKE_C_COMPILER}")
message(STATUS "Compiler CXX: ${CMAKE_CXX_COMPILER}")

file(GLOB_RECURSE SOURCES_CPP src/*.cpp)

add_executable(main_exe)
target_sources(main_exe PRIVATE ${SOURCES_CPP})
target_include_directories(main_exe PRIVATE include)