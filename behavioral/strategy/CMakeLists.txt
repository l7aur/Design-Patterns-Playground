cmake_minimum_required(VERSION 3.21)

project(strategy)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
)

file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS
    "include/*.hpp"
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
)

target_include_directories(${PROJECT_NAME} PRIVATE
    include/
)