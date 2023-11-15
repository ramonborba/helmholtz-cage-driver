/**
 * \file heartbeat.hpp
 * 
 * \brief Hearbeat task header
 * 
 * This task blinks the ESP32 DevKit on board LED for a visual indication that the MCU is running
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 14-11-2023
 */

#ifndef _HEARTBEAT_HPP_
#define _HEARTBEAT_HPP_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/* Task properties */
#define TASK_HEARTBEAT_NAME                 "TaskHeartbeat"
#define TASK_HEARTBEAT_STACK_SIZE           2048
#define TASK_HEARTBEAT_PRIORITY             1
#define TASK_HEARTBEAT_PERIOD_MS            500
#define TASK_HEARTBEAT_CORE                 0
#define TASK_HEARTBEAT_INIT_TIMEOUT_MS      2000

#define HEARTBEAT_LED_PIN                   2


extern TaskHandle_t taskHeartbeatHandle;

/**
 * \brief Heartbeat task
 * 
 * \param pvParameters Not used
 */
void taskHeartbeat(void *pvParameters);

#endif  /* _HEARTBEAT_HPP_ */