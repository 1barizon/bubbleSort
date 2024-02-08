cmake_minimum_required(VERSION 3.0.0)
project(proj VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(proj main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(proj PRIVATE sfml-system sfml-network sfml-graphics sfml-window)


add_custom_target(run
COMMAND ${PROJECT_NAME}
DEPENDS ${PROJECT_NAME}
WORKING_DIRECTORY ${CMAKE_PROJCT_DIR}
)