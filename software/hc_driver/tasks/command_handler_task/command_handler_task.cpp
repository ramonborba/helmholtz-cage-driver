/**
 * \file command_handler_task.cpp
 * 
 * \brief Command handler task implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 06-12-2023
 */

#include "command_handler_task.hpp"
#include "Logger.hpp"
#include "CoilDriver.hpp"
#include "HostPC.hpp"

#include "esp_log.h"

static const char* TAG = "Command Handler Task";

TaskHandle_t tskCmdHandlerTaskHandle;

void CommandHandlerTask(void *pvParameters) {
    ESP_LOGI(TAG, "Created Command Handler Task");
    xTaskGenericNotifyStateClear(tskCmdHandlerTaskHandle, 0);
    xTaskGenericNotifyStateClear(tskCmdHandlerTaskHandle, 1);
    uint32_t cmd;
    uint32_t value;

    CoilDriver axisX (idf::GPIONum(27), idf::I2CAddress(0x00));
    CoilDriver axisY (idf::GPIONum(26), idf::I2CAddress(0x01));
    CoilDriver axisZ (idf::GPIONum(25), idf::I2CAddress(0x02));

    Logger& log { Logger::GetInstance() };

    HostPC& pc { HostPC::GetInstance() };

    while (true) {
        xTaskGenericNotifyWait(0, ULONG_MAX, ULONG_MAX, &cmd, portMAX_DELAY);
        ESP_LOGI(TAG, "Received command: %lu", cmd);
        switch (cmd)
        {
        case 1:
            xTaskGenericNotifyWait(1, ULONG_MAX, ULONG_MAX, &value, portMAX_DELAY);
            axisX.SetSource(value);
            log.Add(LogData(Event(cmd, value)));
            ESP_LOGI(TAG, "Set X axis to : %lu", value);
            break;
       
        case 2:
            xTaskGenericNotifyWait(1, ULONG_MAX, ULONG_MAX, &value, portMAX_DELAY);
            axisY.SetSource(value);
            log.Add(LogData(Event(cmd, value)));
            ESP_LOGI(TAG, "Set Y axis to : %lu", value);
            break;

        case 3:
            xTaskGenericNotifyWait(1, ULONG_MAX, ULONG_MAX, &value, portMAX_DELAY);
            axisZ.SetSource(value);
            log.Add(LogData(Event(cmd, value)));
            ESP_LOGI(TAG, "Set Z axis to : %lu", value);
            break;

        case 4:
            pc.SendLog();
            ESP_LOGI(TAG, "Sent event log to HostPC");
            break;

        default:
            break;
        }
    }
    vTaskSuspend(tskCmdHandlerTaskHandle);
}
