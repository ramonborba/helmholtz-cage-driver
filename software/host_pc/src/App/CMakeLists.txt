# Add library
add_library(App App.cpp)

# Link with project compiler flags
target_link_libraries(App PRIVATE proj_compiler_flags)

# Set include directories
target_include_directories(App PUBLIC include)