/**
 * \file Clock.hpp
 *
 * \brief Clock class header file
 *
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 *
 * \version 0.1
 *
 * \date 17-11-2023
 */

#ifndef _CLOCK_HPP_
#define _CLOCK_HPP_

class Clock {
public:
    Clock(int t_hr, int t_min, int t_sec, bool t_isPm);
    ~Clock();
    void setClock(int t_hr, int t_min, int t_sec, bool t_isPm);
    void readClock(int& t_hr, int& t_min, int& t_sec, bool& t_isPm);
    void advance();

protected:
    int m_hr;
    int m_min;
    int m_sec;
    bool m_isPM;
};

#endif /* _CLOCK_HPP_ */