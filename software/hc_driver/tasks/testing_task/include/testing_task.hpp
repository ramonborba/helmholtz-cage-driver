/**
 * \file testing_task.hpp
 * 
 * \brief Task for testing new components during development
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 15-11-2023
 */

#ifndef _TESTING_TASK_HPP_
#define _TESTING_TASK_HPP_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/* Task properties */
#define TASK_TESTING_TASK_NAME                 "TaskTesting"
#define TASK_TESTING_TASK_STACK_SIZE           2048
#define TASK_TESTING_TASK_PRIORITY             1
#define TASK_TESTING_TASK_PERIOD_MS            500
#define TASK_TESTING_TASK_CORE                 0
#define TASK_TESTING_TASK_INIT_TIMEOUT_MS      2000


extern TaskHandle_t taskTestingHandle;

/**
 * \brief Testing task
 * 
 * \param pvParameters Not used
 */
void taskTesting(void *pvParameters);

#endif  /* _TESTING_TASK_HPP_ */
