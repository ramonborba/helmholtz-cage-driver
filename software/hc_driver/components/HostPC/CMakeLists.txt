idf_component_register(SRCS "HostPC.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES Host Logger uart_cxx command_handler_task)
