file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.cxx")
add_library(${TARGET_NAME} ${SOURCES})
target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(test)

#Target specific code:
#target_compile_options(${TARGET_NAME} PUBLIC "-fno-elide-constructors")