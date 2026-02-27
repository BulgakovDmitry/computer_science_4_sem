cmake_minimum_required(VERSION 3.16)

project(dynamic_animals LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(dynamic_animals
    src/main.c
    src/obj.c
    src/dog.c
    src/cat.c
)

target_include_directories(dynamic_animals PRIVATE
    include
)

target_compile_options(dynamic_animals PRIVATE
    -Wall -Wextra -Wpedantic
)