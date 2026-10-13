cmake_minimum_required(VERSION 3.20)

project(PassCheck)

set(CMAKE_CXX_STANDARD 20)

set(Qt6_DIR "D:/Qt/6.11.2/mingw_64/lib/cmake/Qt6")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(PassCheck
        main.cpp
)

target_link_libraries(PassCheck
        Qt6::Widgets
)