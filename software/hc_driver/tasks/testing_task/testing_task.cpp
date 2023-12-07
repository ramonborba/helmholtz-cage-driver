/**
 * \file testing_task.cpp
 * 
 * \brief Testing task implmentation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 15-11-2023
 */

#include "testing_task.hpp"
#include "freertos/queue.h"

#include "CurrentSource.hpp"

#include "esp_log.h"

static const char* TAG = "TESTING";

TaskHandle_t tskTestingTaskHandle;

void TestingTask(void *pvParameters) {
    vTaskSuspend(tskTestingTaskHandle);
}
