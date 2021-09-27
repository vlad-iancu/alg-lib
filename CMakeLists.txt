cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
project(alg)

option(INSTALL_GTEST "Enable installation of googletest. (Projects embedding googletest may want to turn this OFF.)" OFF)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
add_compile_definitions(TEST_INPUT_DIR="${TEST_DIR}")

enable_testing()
add_custom_target(tests ${CMAKE_CTEST_COMMAND} -V)
add_custom_target(docu COMMAND doxygen ${PROJECT_SOURCE_DIR}/doxy.conf)

list(APPEND APP_DIRS "algorithm" "data_structure" "driver_program" "util")
foreach(APP_DIR ${APP_DIRS})
    file(GLOB APP_SUBDIRS ${APP_DIR}/*)
    foreach(APP_SUBDIR ${APP_SUBDIRS})
        if(IS_DIRECTORY ${APP_SUBDIR})
            get_filename_component(COMPONENT_NAME ${APP_SUBDIR} NAME)
            string(REPLACE " " "_" COMPONENT_NAME ${COMPONENT_NAME})
            string(REPLACE "-" "_" COMPONENT_NAME ${COMPONENT_NAME})

            get_filename_component(COMPONENT_GROUP ${APP_DIR} NAME)
            string(REPLACE " " "_" COMPONENT_GROUP ${COMPONENT_GROUP})
            string(REPLACE "-" "_" COMPONENT_GROUP ${COMPONENT_GROUP})

            set(TARGET_NAME ${COMPONENT_GROUP}_${COMPONENT_NAME})
            string(TOUPPER ${TARGET_NAME} TARGET_NAME)
            message(STATUS target:${TARGET_NAME})
            message(STATUS component:${COMPONENT_NAME})
            set(${TARGET_NAME} ${CMAKE_PROJECT_NAME}_${COMPONENT_GROUP}_${COMPONENT_NAME})
        endif()
    endforeach()
endforeach()

foreach(APP_DIR ${APP_DIRS})
    file(GLOB APP_SUBDIRS ${APP_DIR}/*)
    foreach(APP_SUBDIR ${APP_SUBDIRS})
        if(IS_DIRECTORY ${APP_SUBDIR})
            get_filename_component(COMPONENT_NAME ${APP_SUBDIR} NAME)
            string(REPLACE " " "_" COMPONENT_NAME ${COMPONENT_NAME})
            string(REPLACE "-" "_" COMPONENT_NAME ${COMPONENT_NAME})

            get_filename_component(COMPONENT_GROUP ${APP_DIR} NAME)
            string(REPLACE " " "_" COMPONENT_GROUP ${COMPONENT_GROUP})
            string(REPLACE "-" "_" COMPONENT_GROUP ${COMPONENT_GROUP})

            set(TARGET_NAME ${CMAKE_PROJECT_NAME}_${COMPONENT_GROUP}_${COMPONENT_NAME})
            add_subdirectory(${APP_SUBDIR})
        endif()
    endforeach()
endforeach()

