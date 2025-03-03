cmake_minimum_required(VERSION 3.16)
project(ChoreTracker)

# QT recommends cmake, add whatever we need for that

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O3 -flto=auto \
     -Wall -Wextra -Wpedantic -Werror \
     -Wnrvo -Wshadow -Wsign-conversion -Wconversion -Wmisleading-indentation -Wnull-dereference -Wdouble-promotion \
     -Wunused -Wduplicated-cond -Wduplicated-branches -Wuseless-cast -Wold-style-cast \
     -Wnon-virtual-dtor -Woverloaded-virtual -Wcast-align")

add_executable(chore_tracker.exe app.cpp chore.cpp encryption.cpp household_manager.cpp household.cpp user_manager.cpp user.cpp main.cpp)
