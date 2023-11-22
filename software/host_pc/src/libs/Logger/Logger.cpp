/**
 * \file Logger.cpp
 * 
 * \brief Logger class implmentation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 17-11-2023
 */

#include <ctime>
#include <iostream>
#include <format>

#include "Logger.hpp"

static const char* TAG = "Logger Class";

LogData::LogData(Event t_event) : m_deviceId (21031997), m_timestamp (0,0,0,0,0,0,0), m_event (t_event) {
    time_t now;
    time(&now);
    // setenv("TZ", "UTC-3", 1);
    tm time;
    localtime_r(&now, &time);
    int hour = time.tm_hour > 13 ? time.tm_hour - 12 : time.tm_hour;
    bool ispm = time.tm_hour > 12;
    m_timestamp.setClock(hour, time.tm_min, time.tm_sec, ispm);
    m_timestamp.setCalendar(time.tm_mday, time.tm_mon+1, time.tm_year+1900);
    // std::cout << *this;
}

Logger& Logger::GetInstance() {
    static Logger singleton;
    return singleton;
}

void Logger::Add(Event t_event) {
    m_logQueue.Enqueue(LogData(t_event));
}

Event Logger::RetrieveEvent() {
    LogData logData = m_logQueue.Dequeue();
    return logData.GetEvent();
}

LogData Logger::RetrieveLogData() {
    return m_logQueue.Dequeue();
}

void Logger::ListAll() {
    m_logQueue.ListAll();
}

void Logger::ListInterval() {

}

Logger::Logger() : m_logQueue () {

}