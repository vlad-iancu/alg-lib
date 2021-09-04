file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.cxx")
add_executable(${TARGET_NAME} ${SOURCES})
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Target specific code:
message(STATUS ${DATA_STRUCTURE_GRAPH})