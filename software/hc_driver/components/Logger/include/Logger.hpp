/**
 * \file Logger.hpp
 * 
 * \brief Logger class  responsoble for storing events occurrred in a queue to be sent to the hosts
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 17-11-2023
 */

#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include "ClockCalendar.hpp"
#include "Queue.hpp"

// TODO: Implement event class
class Event {
public:
    Event(int t_cmd, int t_value) : m_cmd { t_cmd}, m_value { t_value} {}

private:
    int m_cmd;
    int m_value;
};
class LogData
{
public:
    LogData(Event t_event);
    
    Event GetEvent() { return m_event; }

private:
    uint32_t m_deviceId;
    ClockCalendar m_timestamp;
    Event m_event;
};


class Logger
{
public:
    static Logger& GetInstance();
    void Add(Event t_data);
    void Add(LogData t_data);
    Event RetrieveEvent();
    LogData RetrieveLogData();
    bool IsEmpty() { return m_logQueue.IsEmpty(); };

    Logger(const Logger&) = delete;
    void operator= (const Logger&) = delete;

private:
    Logger();
    Queue<LogData> m_logQueue;
};

#endif /* _LOGGER_HPP_ */