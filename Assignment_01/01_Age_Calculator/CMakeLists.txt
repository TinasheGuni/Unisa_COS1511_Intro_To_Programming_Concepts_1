cmake_minimum_required(VERSION 3.5)

project(01_Age_Calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(01_Age_Calculator main.cpp)

include(GNUInstallDirs)
install(TARGETS 01_Age_Calculator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
