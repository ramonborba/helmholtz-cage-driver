/**
 * \file hc_driver.cpp
 * 
 * \brief Application entry point
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 14-11-2023
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "tasks_api.hpp"

extern "C" void app_main(void)
{
    createTasks();
}