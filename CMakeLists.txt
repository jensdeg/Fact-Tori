cmake_minimum_required(VERSION 3.10)
project(Fact-Tori LANGUAGES C CXX)

add_executable(Fact-Tori src/main.cpp src/world/world.cpp src/controls/camera.cpp src/controls/placement.cpp)

set(SFML_LIB_DIR "${CMAKE_SOURCE_DIR}/thirdparty/lib")

target_link_libraries(Fact-Tori
    debug     ${SFML_LIB_DIR}/sfml-graphics-d.lib
    optimized ${SFML_LIB_DIR}/sfml-graphics.lib
    debug     ${SFML_LIB_DIR}/sfml-audio-d.lib
    optimized ${SFML_LIB_DIR}/sfml-audio.lib
    debug     ${SFML_LIB_DIR}/sfml-network-d.lib
    optimized ${SFML_LIB_DIR}/sfml-network.lib
    debug     ${SFML_LIB_DIR}/sfml-window-d.lib
    optimized ${SFML_LIB_DIR}/sfml-window.lib
    debug     ${SFML_LIB_DIR}/sfml-system-d.lib
    optimized ${SFML_LIB_DIR}/sfml-system.lib
)

include_directories(${CMAKE_SOURCE_DIR}/thirdparty/include)

target_include_directories(Fact-Tori PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/include")


set(RESOURCES_FOLDER "${CMAKE_SOURCE_DIR}/resources")
set(DESTINATION_FOLDER "${CMAKE_BINARY_DIR}/debug/resources")
file(MAKE_DIRECTORY ${DESTINATION_FOLDER})
add_custom_command(
    TARGET Fact-Tori POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${RESOURCES_FOLDER}
        ${DESTINATION_FOLDER}
)

set(SFML_BIN_DIR "${CMAKE_SOURCE_DIR}/thirdparty/bin")
foreach(mod IN ITEMS graphics audio network window system)
    add_custom_command(TARGET Fact-Tori POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<IF:$<CONFIG:Debug>,${SFML_BIN_DIR}/debug/sfml-${mod}-d-2.dll,${SFML_BIN_DIR}/release/sfml-${mod}-2.dll>
            $<TARGET_FILE_DIR:Fact-Tori>/$<IF:$<CONFIG:Debug>,sfml-${mod}-d-2.dll,sfml-${mod}-2.dll>
    )
endforeach()


set_property(TARGET Fact-Tori PROPERTY CXX_STANDARD 17)
set_property(TARGET Fact-Tori PROPERTY CXX_STANDARD_REQUIRED on)