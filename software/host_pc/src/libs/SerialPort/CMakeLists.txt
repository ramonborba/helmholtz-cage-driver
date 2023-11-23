# Add library
add_library(SerialPort SerialPort.cpp)

# Link with project compiler flags
target_link_libraries(SerialPort PRIVATE proj_compiler_flags)

# Set include directories
target_include_directories(SerialPort
    PUBLIC
        "include"
)

