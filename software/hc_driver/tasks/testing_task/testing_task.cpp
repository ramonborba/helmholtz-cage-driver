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
#include "Queue.hpp"

#include "esp_log.h"

const char* TAG = "TESTING";

TaskHandle_t taskTestingHandle;

typedef struct
{
    uint32_t data;
} test;


void taskTesting(void *pvParameters) {
    Queue<int> lq;
    Node<int> node (42);
    lq.Enqueue(node);
    node.data = 43;
    lq.Enqueue(node);
    node.data = 44;
    lq.Enqueue(node);
    
    Node<int> t = lq.Dequeue();
    ESP_LOGI(TAG, "Value: %i", t.data);
    t = lq.Dequeue();
    ESP_LOGI(TAG, "Value: %i", t.data);
    t = lq.Dequeue();
    ESP_LOGI(TAG, "Value: %i", t.data);
    
    vTaskDelete(taskTestingHandle);
}
