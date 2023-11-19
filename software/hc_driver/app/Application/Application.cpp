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
#include "HostPC.hpp"
#include "HostMobile.hpp"

static const char* TAG = "Application";

#define HEARTBEAT_LED_PIN       2
#define HEARTBEAT_PERIOD_MS     500
static TaskHandle_t tskHeartbeatTaskHandle;

Application::Application() : m_Hosts { &HostPC::GetInstance(), &HostMobile::GetInstance() } {

}

void Application::Start() {
    ESP_LOGI(TAG, "Stating application.");

    Application::GetInstance().xCreateTasks();
}

void Application::xTaskHeartbeat(void * pvParameters) {

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

    // Create heartbeat task
    err = xTaskCreatePinnedToCore(xTaskHeartbeat,
                            "Heartbeat Task",
                            2048,
                            nullptr,
                            0,
                            &tskHeartbeatTaskHandle,
                            tskNO_AFFINITY
                            );
    if (err != pdPASS) {
        ESP_LOGE(TAG, "Error creating %s", TASK_TESTING_TASK_NAME);
    }

    // Create hosts task
    for (auto &host : m_Hosts)
    {
        const TaskParameters_t tsk = host->GetEventHandlerTaskParams();
        err = xTaskCreatePinnedToCore(tsk.pvTaskCode,
                                      tsk.pcName,
                                      tsk.usStackDepth,
                                      tsk.pvParameters,
                                      tsk.uxPriority,
                                      host->GetEventHandlerTaskHandle(),
                                      tskNO_AFFINITY
                                      );
        if (err != pdPASS) {
            ESP_LOGE(TAG, "Error creating %s", tsk.pcName);
        }
    }
    
}

Application Application::m_Singleton;