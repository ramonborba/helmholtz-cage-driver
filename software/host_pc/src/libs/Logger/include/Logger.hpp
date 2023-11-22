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

#include <cstdint>
#include <iostream>
#include <format>

#include "ClockCalendar.hpp"
#include "Queue.hpp"

// TODO: Implement event class
class Event {
public:
    Event(int t_data) : m_data { t_data} {}

    friend std::ostream& operator<< (std::ostream& out, Event& e) {
        out << "Event Data: " << e.m_data;
        return out;
    }

private:
    int m_data;
};

class LogData
{
public:
    LogData(Event t_event);

    Event GetEvent() { return m_event; }

    friend std:: ostream& operator<< (std::ostream& out, LogData& log) {
        out << std::format("Device ID: {}\n", log.m_deviceId);
        out << std::format("Timestamp: {}\n", log.m_timestamp.Print());
        out << log.m_event << "\n";
        return out;
    }

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
    Event RetrieveEvent();
    LogData RetrieveLogData();
    void ListAll();
    void ListInterval();

    Logger(const Logger&) = delete;
    void operator= (const Logger&) = delete;

private:
    Logger();
    Queue<LogData> m_logQueue;
};

#endif /* _LOGGER_HPP_ */