cmake_minimum_required(VERSION 3.10)
project(Fact-Tori LANGUAGES C CXX)

add_executable(Fact-Tori src/main.cpp)

target_link_libraries(Fact-Tori ${CMAKE_SOURCE_DIR}/lib/sfml-graphics.lib)
target_link_libraries(Fact-Tori ${CMAKE_SOURCE_DIR}/lib/sfml-audio.lib)
target_link_libraries(Fact-Tori ${CMAKE_SOURCE_DIR}/lib/sfml-network.lib)
target_link_libraries(Fact-Tori ${CMAKE_SOURCE_DIR}/lib/sfml-window.lib)
target_link_libraries(Fact-Tori ${CMAKE_SOURCE_DIR}/lib/sfml-system.lib)

include_directories(${CMAKE_SOURCE_DIR}/include)

set_property(TARGET Fact-Tori PROPERTY CXX_STANDARD 17)
set_property(TARGET Fact-Tori PROPERTY CXX_STANDARD_REQUIRED on)