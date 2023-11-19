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

static const char* TAG = "Logger Class";

LogData::LogData(Event t_event) : m_deviceId (21031997), m_timestamp (0,0,0,0,0,0,0), m_event (t_event) {
    time_t now;
    time(&now);
    setenv("TZ", "UTC-3", 1);
    tm time;
    localtime_r(&now, &time);
    int hour = time.tm_hour > 12 ? time.tm_hour - 12 : time.tm_hour;
    bool ispm = time.tm_hour > 12;
    m_timestamp.setClock(hour, time.tm_min, time.tm_sec, ispm);
    m_timestamp.setCalendar(time.tm_mday, time.tm_mon, time.tm_year);
    ESP_LOGI(TAG, "%i-%i-%i %ih%im%is %s", time.tm_mday, time.tm_mon, time.tm_year, hour, time.tm_min, time.tm_sec, ispm ? "PM":"AM");
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

void LogData::printDebug() {
    tm t;
    bool ispm;
    m_timestamp.readCalendar(t.tm_mday, t.tm_mon, t.tm_year);
    m_timestamp.readClock(t.tm_hour, t.tm_min, t.tm_sec, ispm);
    ESP_LOGI(TAG, "DeviceID: %lu", m_deviceId);
    ESP_LOGI(TAG, "Temstamp: %i-%i-%i|%ih%im%is%s", t.tm_mday, t.tm_mon, t.tm_year, t.tm_hour, t.tm_min, t.tm_sec, ispm ? "PM":"AM");
    ESP_LOGI(TAG, "Event: %s", m_event.print());
}