cmake_minimum_required(VERSION 3.16)

# 项目名称
project(ContactBook LANGUAGES CXX)

# C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 头文件包含路径（让代码能找到 include 里的 .h 文件）
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加所有源文件
add_executable(${PROJECT_NAME}
    src/main.cpp
)

