cmake_minimum_required(VERSION 3.25.1)

# Create project
project(HostPC CXX)

# Set build type
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_COLOR_MAKEFILE ON)

# Export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# Colored diagnostics
set(CMAKE_COLOR_DIAGNOSTICS ON)

# Create interface library for compiler options
add_library(proj_compiler_flags INTERFACE)

# Specify the C++ standard
target_compile_features(proj_compiler_flags INTERFACE cxx_std_23)

# List of GCC compiler options
set(GCC_WARNINGS
    -Wall
    -Wextra # reasonable and standard
    -Wshadow # warn the user if a variable declaration shadows one from a parent context
    -Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor. This helps catch hard to track down memory errors
    -Wunused # warn on anything being unused
    -Wpedantic # warn if non-standard C++ is used
    -Wnull-dereference # warn if a null dereference is detected
)

# Set compile options
target_compile_options(proj_compiler_flags INTERFACE ${GCC_WARNINGS})

# Add src subdirectory
add_subdirectory(src)