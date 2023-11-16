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

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/idf_additions.h"
#include "gpio_cxx.hpp"

#include "esp_log.h"

#include "Application.hpp"
#include "application_tasks.hpp"

static const char* TAG = "Application Class";


void Application::Start() {
    ESP_LOGI(TAG, "Stating application.");

    Application::GetInstance().xCreateTasks();
}

void Application::Heartbeat() {

    idf::GPIO_Output ledHeartbeat (idf::GPIONum(HEARTBEAT_LED_PIN));
    bool active = false;

    while (true)
    {
        TickType_t lastWakeTime = xTaskGetTickCount();
        if (active)
        {
            ledHeartbeat.set_high();
        }
        else
        {
            ledHeartbeat.set_low();
        }
        active = !active;

        xTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(HEARTBEAT_PERIOD_MS));
    }

}

Application& Application::GetInstance() {
    return m_Singleton;
}

void Application::xCreateTasks() {

    BaseType_t err;

    ESP_LOGI(TAG, "Creating tasks.");
    // Create testing task
    err = xTaskCreatePinnedToCore(TestingTask,
                            TASK_TESTING_TASK_NAME,
                            TASK_TESTING_TASK_STACK_SIZE,
                            nullptr,
                            TASK_TESTING_TASK_PRIORITY,
                            &tskTestingTaskHandle,
                            tskNO_AFFINITY
                            );
    if (err != pdPASS) {
        ESP_LOGE(TAG, "Error creating %s", TASK_TESTING_TASK_NAME);
    }
}

Application Application::m_Singleton;