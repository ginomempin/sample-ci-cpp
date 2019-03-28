cmake_minimum_required (VERSION 3.5.1)

set(CMAKE_C_COMPILER    "gcc")
set(CMAKE_CXX_COMPILER  "g++")
set(CMAKE_CXX_STANDARD  14)

set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} --coverage")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

enable_testing()

########################################################################
# Download a local copy of GoogleTest in build/
#
# Alternatives to this are:
#   1. Downloading GoogleTest separately somewhere then referencing the
#      source and include directories here. That could make for a simpler
#      CMake config but is problematic for continuous integration setups
#      where the CI would then become dependent on the environment.
#   2. Maintaining a static copy of GoogleTest along with the source code.
#      Aside from committing unnecessary code to the repo, it will make it
#      difficult to maintain versions of GoogleTest

configure_file(CMakeLists.txt.googletest.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download
)
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download
)
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
    ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
    EXCLUDE_FROM_ALL)
########################################################################

set(APP
    "calculator"
)

set(APP_HEADERS
    "include"
)

set(APP_SOURCES
    "src/Calculator.cpp"
)

set(APP_TESTER
    "calculator_tests"
)

set(APP_TESTS
    "tests/CalculatorTest.cpp"
)

project(${APP}
    VERSION 1.0.0
    LANGUAGES "CXX"
)

include_directories(${APP_HEADERS})

add_executable(${APP}
    "${APP_SOURCES}"
    "src/main.cpp"
)

add_executable(${APP_TESTER}
    "${APP_SOURCES}"
    "${APP_TESTS}"
)

target_link_libraries(${APP_TESTER}
    gtest_main
    pthread
)
