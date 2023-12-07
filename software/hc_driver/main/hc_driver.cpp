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
#include <sys/time.h>

#include "Application.hpp"

#include "esp_log.h"

extern "C" void app_main(void)
{
    struct timeval tv { .tv_sec = 1701876630 };
    setenv("TZ", "UTC+3", 1);
    tzset();
    settimeofday(&tv, NULL);
    esp_log_level_set("*", ESP_LOG_DEBUG);
    Application::Start();
    // Application::Heartbeat();
}