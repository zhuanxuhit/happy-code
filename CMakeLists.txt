# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.6)
# 项目信息
project(happy_code)

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CXX_FLAGS
        -W -Wall -Wfatal-errors
        -g
        -rdynamic
        )
#set(SOURCE_FILES main.cpp sds.cpp)
# 指定生成目标
#add_executable(happy_code ${SOURCE_FILES})
#add_subdirectory(src)
add_subdirectory(src)
add_subdirectory(geek_time_cpp)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
# aux_source_directory(. DIR_SRCS)

# 添加 math 子目录
# add_subdirectory(math)

# 添加链接库
# target_link_libraries(Demo MathFunctions)
