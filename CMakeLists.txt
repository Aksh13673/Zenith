cmake_minimum_required(VERSION 3.10)
project(ZenithC VERSION 1.0.0 LANGUAGES C)

# Tell the computer Zenith-C is just a header file (.h)
add_library(ZenithC INTERFACE)
target_include_directories(ZenithC INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Tell the computer to copy the file to the "Include" folder
install(FILES zenith_c.h DESTINATION include)
