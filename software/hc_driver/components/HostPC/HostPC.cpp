/**
 * \file HostPC.cpp
 * 
 * \brief HostPC class implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 18-11-2023
 */

#include "HostPC.hpp"

#include "esp_log.h"

static const char* TAG = "HostPC";

const TaskParameters_t HostPC::m_TaskParams {
    .pvTaskCode = xUartEventHandlerTask,
    .pcName = "HostPC Uart Handler Task",
    .usStackDepth = 2048,
    .pvParameters = nullptr,
    .uxPriority = 10
};

TaskHandle_t HostPC::m_TaskHandle;

HostPC::HostPC() : m_Uart(m_UartPortNum, 512, 512, &m_UartEventQueue, 10) {
    m_Uart.set_config(m_UartConfig);
    m_Uart.set_pins(16, 17, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}

HostPC& HostPC::GetInstance() {
    static HostPC singleton;
    return singleton;
}

void HostPC::SendLog() {

}

const TaskParameters_t HostPC::GetEventHandlerTaskParams() {
    return m_TaskParams;
}

TaskHandle_t* HostPC::GetEventHandlerTaskHandle() {
    return &m_TaskHandle;
}

void HostPC::xUartEventHandlerTask(void* pvParameters) {
    ESP_LOGI(TAG, "Created %s", m_TaskParams.pcName);
    vTaskSuspend(m_TaskHandle);
}