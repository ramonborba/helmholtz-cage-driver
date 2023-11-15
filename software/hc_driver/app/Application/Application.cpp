/**
 * \file Application.cpp
 * 
 * \brief Application class implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 15-11-2023
 */

#include "esp_log.h"

#include "Application.hpp"
#include "tasks_api.hpp"

static const char* TAG = "Application";

void Application::start() {
    ESP_LOGI(TAG, "Stating application.");

    ESP_LOGI(TAG, "Creating tasks.");
    createTasks();
}