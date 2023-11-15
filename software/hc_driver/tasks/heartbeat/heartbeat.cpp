/**
 * \file heartbeat.cpp
 * 
 * \brief Heartbeat task implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 14-11-2023
 */

#include "heartbeat.hpp"
#include "gpio_cxx.hpp"
#include "esp_log.h"


TaskHandle_t taskHeartbeatHandle;

static const char* TAG = TASK_HEARTBEAT_NAME;

void taskHeartbeat(void *pvParameters)
{
    ESP_LOGI(TAG, "Created Heartbeak Task");
    idf::GPIO_Output Heartbeat_LED(idf::GPIONum(HEARTBEAT_LED_PIN));
    bool active = false;

    while (true)
    {
        TickType_t lastWakeTime = xTaskGetTickCount();
        if (active)
        {
            Heartbeat_LED.set_high();
        }
        else
        {
            Heartbeat_LED.set_low();
        }
        active = !active;

        xTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(TASK_HEARTBEAT_PERIOD_MS));
    }
    

}