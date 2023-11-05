cmake_minimum_required(VERSION 3.20)

# Set project information
project(
  BoxGrid
  VERSION 1.0
  DESCRIPTION "Program to draw a checkerboard"
  LANGUAGES CXX)

# Add an executable target
add_executable(${PROJECT_NAME})

# Define Cxx standard
set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES CXX_STANDARD 17
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS OFF)

# Add source files
target_sources(${PROJECT_NAME} PRIVATE src/BoxGrid.cpp)

# Fetch SimpleCxxLib
include(FetchContent)
FetchContent_Declare(
  SimpleCxxLib
  GIT_REPOSITORY https://gitee.com/stickmind/SimpleCxxLib.git
  GIT_TAG main)
FetchContent_MakeAvailable(SimpleCxxLib)

# Add libraries
target_link_libraries(${PROJECT_NAME} PRIVATE SimpleCxxLib)

# Copy Java backend
file(COPY ${SimpleCxxLib_SOURCE_DIR}/java/spl.jar
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
