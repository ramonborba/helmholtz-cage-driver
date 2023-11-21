# Add library
add_library(App App.cpp)

# Set include directories
target_include_directories(App PUBLIC include)

# Link with project compiler flags
target_link_libraries(App PRIVATE proj_compiler_flags)

# Link dependencies
target_link_libraries(App
    PRIVATE
        ClockCalendar
)