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

#include "Logger.hpp"

#include "esp_log.h"

static const char* TAG = "Logger";

LogData::LogData(Event t_event) : m_deviceId (21031997), m_timestamp (0,0,0,0,0,0,0), m_event (t_event) {
    time_t now;
    time(&now);
    tm time;
    localtime_r(&now, &time);
    int hour = time.tm_hour > 12 ? time.tm_hour - 12 : time.tm_hour;
    bool ispm = time.tm_hour > 12;
    m_timestamp.setClock(hour, time.tm_min, time.tm_sec, ispm);
    m_timestamp.setCalendar(time.tm_mday, time.tm_mon+1, time.tm_year+1900);
    ESP_LOGD(TAG, "%i-%i-%i %ih%im%is %s", time.tm_mday, time.tm_mon, time.tm_year, time.tm_hour, time.tm_min, time.tm_sec, ispm ? "PM":"AM");
}

Logger& Logger::GetInstance() {
    static Logger singleton;
    return singleton;
}

void Logger::Add(Event t_data) {
    m_logQueue.Enqueue(LogData(t_data));
}

Event Logger::RetrieveEvent() {
    LogData logData = m_logQueue.Dequeue();
    return logData.GetEvent();
}

LogData Logger::RetrieveLogData() {
    return m_logQueue.Dequeue();
}

Logger::Logger() : m_logQueue () {

}