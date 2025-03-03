cmake_minimum_required(VERSION 3.10)
project(week3)

set(CMAKE_CXX_STANDARD 20)

set(CODE_PATH week3)

# 递归地将符合模式匹配的文件赋给SRC_FILE
file(GLOB_RECURSE SRC_FILE ${CODE_PATH}/*.cpp)

include_directories(${CODE_PATH} ${CODE_PATH}/include)

add_executable(${PROJECT_NAME} ${SRC_FILE})