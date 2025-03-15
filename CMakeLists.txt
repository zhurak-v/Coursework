cmake_minimum_required(VERSION 3.20)

project(coursework)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/glfw)

set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

file(GLOB IMGUI_SRC 
    ${IMGUI_DIR}/imgui*.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

add_executable(app 
    ${SRC_FILES}
    ${IMGUI_SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/src/gl.c
)

target_include_directories(app PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include  
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
)

target_link_libraries(app glfw)

if(WIN32)
    target_link_libraries(app opengl32)
elseif(UNIX)
    target_link_libraries(app dl pthread)
endif()
