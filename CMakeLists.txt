cmake_minimum_required(VERSION 3.10)

project(CTello)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

find_package(spdlog REQUIRED)


# CTello Shared Library =======================================================

add_library(ctello src/ctello.cpp)

target_include_directories(ctello PRIVATE include)

target_link_libraries(ctello PRIVATE spdlog::spdlog)

install(TARGETS ctello DESTINATION lib)
install(FILES include/ctello.h DESTINATION include)

## Flip -----------------------------------------------------------------------
add_executable(flip examples/flip.cpp)

target_include_directories(flip PRIVATE include)

target_link_libraries(flip ctello)
target_link_libraries(flip ${OpenCV_LIBS})

