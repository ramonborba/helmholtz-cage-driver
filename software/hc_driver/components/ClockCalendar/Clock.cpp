/**
 * \file Clock.cpp
 * 
 * \brief Clock class implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 17-11-2023
 */

#include "Clock.hpp"

Clock::Clock(int t_hr, int t_min, int t_sec, bool t_isPm) : m_hr(t_hr), m_min(t_min), m_sec(t_sec), m_isPM(t_isPm) {
}

Clock::~Clock() {
}

void Clock::setClock(int t_hr, int t_min, int t_sec, bool t_isPm) {
    m_hr = t_hr;
    m_min = t_min;
    m_sec = t_sec;
    m_isPM = t_isPm;
}

void Clock::readClock(int& t_hr, int& t_min, int& t_sec, bool& t_isPm) {
    t_hr = m_hr; 
    t_min = m_min; 
    t_sec = m_sec; 
    t_isPm = m_isPM; 
}

void Clock::advance() {
    m_sec++;
    if (m_sec > 59) {
        m_sec = 0;
        m_min++;
        if (m_min > 59) {
            m_min = 0;
            m_hr++;
            if (m_hr == 12) {
                if (m_isPM) {
                    m_hr = 0;
                    m_isPM = false;
                }
                else {
                    m_isPM = true;
                }
            }
            else if (m_hr > 12) {
                m_hr = 1;
            }
        }
    }
}
