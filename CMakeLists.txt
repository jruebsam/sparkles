cmake_minimum_required(VERSION 2.8.12)
project(Spark LANGUAGES CXX)

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED True)
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(
    spark 
    src/main.cpp
    src/glad.cpp
    src/Shader.cpp
    src/Window.cpp
    src/Canvas.cpp
    src/Agents.cpp
    bindings/imgui_impl_glfw.cpp 
    bindings/imgui_impl_opengl3.cpp
)

target_include_directories(spark PUBLIC inc bindings)
target_link_libraries(spark ${CONAN_LIBS})

add_custom_command(
    TARGET spark POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink              
        ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:spark>/shaders
    COMMENT "Creating symlink to shader directory" VERBATIM
)
