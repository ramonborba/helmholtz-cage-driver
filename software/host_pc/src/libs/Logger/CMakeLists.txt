# Add library
add_library(Logger Logger.cpp)

# Link with project compiler flags
target_link_libraries(Logger PRIVATE proj_compiler_flags)

# Set include directories
target_include_directories(Logger
    PUBLIC
        "include"
)

# Link dependencies
target_link_libraries(Logger
    PUBLIC
        Queue
        ClockCalendar
    )