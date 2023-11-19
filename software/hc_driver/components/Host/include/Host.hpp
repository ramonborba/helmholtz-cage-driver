/**
 * \file Host.hpp
 * 
 * \brief Host interface class header file
 * 
 * This class is deigned to be an abstract base class representing a host for the application
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 18-11-2023
 */

#ifndef _HOST_HPP_
#define _HOST_HPP_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "Logger.hpp"

class Host
{
public:
    Host() : m_log (Logger::GetInstance()) {};

    virtual ~Host() = default;

    virtual void SendLog() = 0;

    virtual const TaskParameters_t GetEventHandlerTaskParams() = 0;
    virtual TaskHandle_t* GetEventHandlerTaskHandle() = 0;

protected:
    Logger& m_log;
};

#endif /* _HOST_HPP_ */