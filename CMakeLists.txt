cmake_minimum_required (VERSION 3.5.1)

set(TARGET
    "calculator"
)

set(HEADERS
    "include"
)

set(SOURCES
    "src/Calculator.cpp"
    "src/main.cpp"
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

project(${TARGET}
    VERSION 1.0.0
    LANGUAGES "CXX"
)

include_directories(${HEADERS})

add_executable(${TARGET}
    "${SOURCES}"
)
