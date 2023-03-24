cmake_minimum_required(VERSION 3.1) # CMake install : https://cmake.org/download/
project(PVZ VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_PREFIX_PATH D:/DevSoftwares/Qt/5.15.12/mingw81_64/) # Qt Kit Dir

set(Qt5_DIR D:/DevSoftwares/Qt/5.15.2/mingw81_64/lib/cmake/Qt5) # 推荐使用set Qt5_DIR的方法,这里对应自己的QT路径
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Widgets Multimedia REQUIRED) # Qt COMPONENTS
set(CMAKE_BUILD_TYPE RELEASE)

include_directories(./include)
# aux_source_directory(./plant SRC)
file(GLOB_RECURSE SRC plants/*.cpp zombie/*.cpp shop/*.cpp ui/*.cpp  )
set(QRC resource/images.qrc)
add_executable(${PROJECT_NAME} WIN32 ${SRC} main.cpp include/mainwindow.h ${QRC} resource/ico.rc)
target_link_libraries(${PROJECT_NAME}  Qt5::Widgets Qt5::Multimedia)