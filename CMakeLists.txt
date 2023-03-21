cmake_minimum_required(VERSION 3.1) # CMake install : https://cmake.org/download/
project(PVZ VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/opt/Qt5.12.12/5.12.12/gcc_64") # Qt Kit Dir
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Widgets Multimedia REQUIRED) # Qt COMPONENTS

include_directories(./include)
# aux_source_directory(./plant SRC)
file(GLOB_RECURSE SRC plants/*.cpp zombie/*.cpp shop/*.cpp ui/*.cpp  )
message(${SRC})

add_executable(${PROJECT_NAME} ${SRC} include/mainwindow.h)
target_link_libraries(${PROJECT_NAME}  Qt5::Widgets Qt5::Multimedia)