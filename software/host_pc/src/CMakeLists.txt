# Add subdirectories
add_subdirectory(App)

# Add executable target
add_executable(hc_host main.cpp)

# Link compiler flags interface library
target_link_libraries(hc_host PRIVATE proj_compiler_flags)

# Link libraries
target_link_libraries(hc_host
    PUBLIC
        App
)