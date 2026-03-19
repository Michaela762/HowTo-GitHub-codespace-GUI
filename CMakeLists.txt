cmake_minimum_required(VERSION 3.15)
project(Hello_world CXX)

set(CMAKE_CXX_STANDARD 20)

# Add sources
set(PROGRAM_SRC
    src/main.cpp
)

add_executable(main.out ${PROGRAM_SRC})

# Include headers
set(HEADERS_DIR "${PROJECT_SOURCE_DIR}/include")
target_include_directories(main.out PRIVATE
    ${HEADERS_DIR}
)

# Platform-specific system libs
if(WIN32)
    target_link_options(main.out PRIVATE
        -static
        -static-libgcc
        -static-libstdc++
    )
endif()
