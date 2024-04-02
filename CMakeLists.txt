cmake_minimum_required(VERSION 3.5)

project(Chess_Swiss_System LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Chess_Swiss_System main.cpp
    newtourmain.h
    person.h person.cpp
    outputs.h
    viewmain.h viewmain.cpp)

include(GNUInstallDirs)
install(TARGETS Chess_Swiss_System
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
