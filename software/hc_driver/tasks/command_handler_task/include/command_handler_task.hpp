/**
 * \file command_handler_task.hpp
 * 
 * \brief Command handler task header
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 06-12-2023
 */

#ifndef _COMMAND_HANDLER_TASK_HPP_
#define _COMMAND_HANDLER_TASK_HPP_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/* Task properties */
#define TASK_COMMAND_HANDLER_TASK_NAME                 "TaskTesting"
#define TASK_COMMAND_HANDLER_TASK_STACK_SIZE           2048
#define TASK_COMMAND_HANDLER_TASK_PRIORITY             5
#define TASK_COMMAND_HANDLER_TASK_PERIOD_MS            500
#define TASK_COMMAND_HANDLER_TASK_CORE                 0
#define TASK_COMMAND_HANDLER_TASK_INIT_TIMEOUT_MS      2000


extern TaskHandle_t tskCmdHandlerTaskHandle;

/**
 * \brief Testing task
 * 
 * \param pvParameters Not used
 */
void CommandHandlerTask(void *pvParameters);

#endif /* _COMMAND_HANDLER_TASK_HPP_ */