cmake_minimum_required(VERSION 3.21)
project(LinkList C)

set(CMAKE_C_STANDARD 99)

add_executable(LinkList main.c inputBuffer.c inputBuffer.h linkList.c linkList.h)
