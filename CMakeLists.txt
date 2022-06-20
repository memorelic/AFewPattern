cmake_minimum_required(VERSION 3.15)

# 设置C++标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_EXTENSIONS OFF)

project(AFewPattern LANGUAGES CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(main)
file(GLOB src CMAKE_CONFIGURE_DEPENDS ./*.cpp ./*.h)
target_sources(main PUBLIC ${src})