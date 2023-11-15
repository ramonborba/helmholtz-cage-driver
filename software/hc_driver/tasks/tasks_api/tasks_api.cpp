/**
 * \file tasks_api.cpp
 * 
 * \brief 
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 14-11-2023
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/idf_additions.h"

#include "esp_log.h"

#include "tasks_api.hpp"
#include "heartbeat.hpp"

static const char* TAG = "TasksApi";

void createTasks(void)
{
    // Create hearbeat task
    BaseType_t err = xTaskCreatePinnedToCore(taskHeartbeat,
                            TASK_HEARTBEAT_NAME,
                            TASK_HEARTBEAT_STACK_SIZE,
                            nullptr,
                            TASK_HEARTBEAT_PRIORITY,
                            &taskHeartbeatHandle,
                            tskNO_AFFINITY
                            );
    if (err != pdPASS) {
        ESP_LOGE(TAG, "Error creating %s", TASK_HEARTBEAT_NAME);
    }
}
