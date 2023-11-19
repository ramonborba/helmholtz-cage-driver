/**
 * \file HostMobile.cpp
 * 
 * \brief HostMobile class implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 18-11-2023
 */

#include "HostMobile.hpp"

#include "esp_log.h"

static const char* TAG = "HostMobile";

const TaskParameters_t HostMobile::m_TaskParams {
    .pvTaskCode = xWiFiEventHandlerTask,
    .pcName = "HostMobile WiFi Handler Task",
    .usStackDepth = 2048,
    .pvParameters = nullptr,
    .uxPriority = 10
};

TaskHandle_t HostMobile::m_TaskHandle;

HostMobile::HostMobile() {
}

HostMobile& HostMobile::GetInstance() {
    static HostMobile singleton;
    return singleton;
}

void HostMobile::SendLog() {
    
}

const TaskParameters_t HostMobile::GetEventHandlerTaskParams() {
    return m_TaskParams;
}

TaskHandle_t* HostMobile::GetEventHandlerTaskHandle() {
    return &m_TaskHandle;
}

void HostMobile::xWiFiEventHandlerTask(void* pvParameters) {
    ESP_LOGI(TAG, "Created %s", m_TaskParams.pcName);
    vTaskDelay(1000);
    vTaskSuspend(m_TaskHandle);
}