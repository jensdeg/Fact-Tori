cmake_minimum_required(VERSION 3.10)
project(Fact-Tori LANGUAGES C CXX)

add_executable(Fact-Tori src/main.cpp src/world/world.cpp src/controls/camera.cpp)

target_link_libraries(Fact-Tori ${CMAKE_SOURCE_DIR}/lib/sfml-graphics-d.lib)
target_link_libraries(Fact-Tori ${CMAKE_SOURCE_DIR}/lib/sfml-audio-d.lib)
target_link_libraries(Fact-Tori ${CMAKE_SOURCE_DIR}/lib/sfml-network-d.lib)
target_link_libraries(Fact-Tori ${CMAKE_SOURCE_DIR}/lib/sfml-window-d.lib)
target_link_libraries(Fact-Tori ${CMAKE_SOURCE_DIR}/lib/sfml-system-d.lib)

include_directories(${CMAKE_SOURCE_DIR}/include)

target_include_directories(Fact-Tori PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/world/include")
target_include_directories(Fact-Tori PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/controls/include")


set(RESOURCES_FOLDER "${CMAKE_SOURCE_DIR}/resources")
set(DESTINATION_FOLDER "${CMAKE_BINARY_DIR}/resources")
file(MAKE_DIRECTORY ${DESTINATION_FOLDER})
add_custom_command(
    TARGET Fact-Tori POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${RESOURCES_FOLDER}
        ${DESTINATION_FOLDER}
)


set_property(TARGET Fact-Tori PROPERTY CXX_STANDARD 17)
set_property(TARGET Fact-Tori PROPERTY CXX_STANDARD_REQUIRED on)