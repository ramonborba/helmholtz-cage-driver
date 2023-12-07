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
#include "Logger.hpp"
#include "command_handler_task.hpp"

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
QueueHandle_t HostPC::m_UartEventQueue;
uart_port_t HostPC::m_UartPortNum = UART_NUM_2;
idf::UARTPort HostPC::m_Uart(m_UartPortNum, 512, 512, &m_UartEventQueue, 10);

HostPC::HostPC() {
    m_Uart.set_config(m_UartConfig);
    m_Uart.set_pins(16, 17, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}

HostPC& HostPC::GetInstance() {
    static HostPC singleton;
    return singleton;
}

void HostPC::SendLog() {
    Logger& log { Logger::GetInstance() };
    while (!log.IsEmpty())
    {
        LogData data { log.RetrieveLogData() };
        m_Uart.write(&data, sizeof(LogData));
    }
    
}

const TaskParameters_t HostPC::GetEventHandlerTaskParams() {
    return m_TaskParams;
}

TaskHandle_t* HostPC::GetEventHandlerTaskHandle() {
    return &m_TaskHandle;
}

void HostPC::xUartEventHandlerTask(void* pvParameters) {
    ESP_LOGI(TAG, "Created %s", m_TaskParams.pcName);

    uart_event_t event;
    uint32_t buffer[2] = {0};

    vTaskDelay(1000);
    while (true)
    {
        if (xQueueReceive(m_UartEventQueue, (void*)&event, (TickType_t)portMAX_DELAY))
        {
            switch (event.type)
            {
            case UART_DATA:
                m_Uart.read(buffer, event.size, portMAX_DELAY);
                ESP_LOGI(TAG, "Received: %li, %li", buffer[0], buffer[1]);
                xTaskGenericNotify(tskCmdHandlerTaskHandle, 0, buffer[0], eSetValueWithOverwrite, nullptr);
                xTaskGenericNotify(tskCmdHandlerTaskHandle, 1, buffer[1], eSetValueWithOverwrite, nullptr);
                break;
            
            default:
                ESP_LOGI(TAG, "UART event received: %d", event.type);
                break;
            }
        }
        
    }
    

    vTaskSuspend(m_TaskHandle);
}