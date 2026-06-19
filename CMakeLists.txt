cmake_minimum_required(VERSION 3.15)

project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(TaskManager
    main.cpp
    Date.cpp
    Worker.cpp
    Task.cpp
    Project.cpp
    TaskManager.cpp
    FileManager.cpp
)