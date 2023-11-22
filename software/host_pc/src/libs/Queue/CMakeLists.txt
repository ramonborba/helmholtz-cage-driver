# Add library
add_library(Queue INTERFACE)

# Link with project compiler flags
target_link_libraries(Queue INTERFACE proj_compiler_flags)

# Set include directories
target_include_directories(Queue
    INTERFACE
        "include"
)

