cmake_minimum_required(VERSION 3.21)
project(lab7)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab7 main.cpp Vector.h Entity.cpp Entity.h Repository/Repository.h Service/Service.cpp Service/Service.h Tests/AllTests.h UI/UI.cpp UI/UI.h)
