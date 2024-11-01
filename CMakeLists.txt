cmake_minimum_required(VERSION 3.15)

project(minisweeper LANGUAGES CXX)

set(CMAKE_MSVC_RUNTIME_LIBRARY "$<$<NOT:$<CONFIG:Debug>>:MultiThreaded>")

add_executable(minisweeper)

set_property(TARGET minisweeper PROPERTY CXX_STANDARD 20)

include(FetchContent)
set(FETCHCONTENT_QUIET OFF)
FetchContent_Declare(raylib URL "https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz")
FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE minisweeper_src "src/*.cpp")
target_sources(minisweeper PRIVATE
  "${minisweeper_src}")

target_include_directories(minisweeper PRIVATE
  "include")

target_link_libraries(minisweeper PRIVATE raylib)
if (APPLE)
  target_link_libraries(minisweeper PRIVATE "-framework IOKit")
  target_link_libraries(minisweeper PRIVATE "-framework Cocoa")
  target_link_libraries(minisweeper PRIVATE "-framework OpenGL")
endif()

target_compile_options(minisweeper PRIVATE "-Wall")
if(MSVC)
  target_link_options(minisweeper PRIVATE "$<$<NOT:$<CONFIG:Debug>>:LINKER:/SUBSYSTEM:WINDOWS,/ENTRY:mainCRTStartup>")
endif()

add_custom_command(
  TARGET minisweeper POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources)
