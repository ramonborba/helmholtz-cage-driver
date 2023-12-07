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
    Event(int t_cmd, int t_value) : m_cmd { t_cmd }, m_value { t_value } {}

    friend std::ostream& operator<< (std::ostream& out, Event& e) {
        out << "Axis: " << e.m_cmd << "\nValue: " << e.m_value << "\n";
        return out;
    }

private:
    int m_cmd;
    int m_value;
};

class LogData
{
public:
    LogData(Event t_event);

    Event& GetEvent() { return m_event; }

    friend std:: ostream& operator<< (std::ostream& out, LogData& log) {
        out << std::format("Device ID: {}\n", log.m_deviceId);
        out << std::format("Timestamp: {}\n", log.m_timestamp.Print());
        out << log.m_event << "\n";
        return out;
    }

    friend bool operator< (LogData& l, ClockCalendar& r) {
        return l.m_timestamp < r;
    }

    friend bool operator> (LogData& l, ClockCalendar& r) {
        return l.m_timestamp > r;
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
    void Add(Event t_event);
    void Add(LogData t_data);
    Event RetrieveEvent();
    LogData RetrieveLogData();
    void ListAll();
    void ListInterval(ClockCalendar t_inStart, ClockCalendar t_inEnd);

    Logger(const Logger&) = delete;
    void operator= (const Logger&) = delete;

private:
    Logger();
    Queue<LogData> m_logQueue;
};

#endif /* _LOGGER_HPP_ */