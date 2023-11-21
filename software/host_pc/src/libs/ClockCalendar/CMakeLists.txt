# Add library
add_library(ClockCalendar ClockCalendar.cpp Clock.cpp Calendar.cpp)

# Link with project compiler flags
target_link_libraries(ClockCalendar PRIVATE proj_compiler_flags)

# Set include directories
target_include_directories(ClockCalendar
    PUBLIC
        "include"
)
