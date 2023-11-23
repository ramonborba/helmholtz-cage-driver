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


    friend bool operator< (Clock& l, Clock&r) {
        if ((l.m_isPM && r.m_isPM) || (!l.m_isPM && !r.m_isPM)) {
            if (l.m_hr < r.m_hr) {
                return true;
            }
            else if ((l.m_hr == r.m_hr) && (l.m_min < r.m_min)){
                return true;
            }
            else if ((l.m_min == r.m_min) && (l.m_sec < r.m_sec)) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (!l.m_isPM && r.m_isPM) {
            return true;
        }
        else {
            return false;
        }
    }

    friend bool operator== (Clock& l, Clock& r) {
        return (l.m_isPM == r.m_isPM) && (l.m_hr == r.m_hr) && (l.m_min == r.m_min) && (l.m_sec == r.m_sec);
    }

    friend bool operator> (Clock& l, Clock& r) {
        return !(l == r) && !(l < r);
    }

    friend bool operator<= (Clock& l, Clock& r) {
        return (l == r) || (l < r);
    }

    friend bool operator>= (Clock& l, Clock& r) {
        return (l == r) && (l > r);
    }

    friend bool operator!= (Clock& l, Clock& r) {
        return !(l == r);
    }

protected:
    int m_hr;
    int m_min;
    int m_sec;
    bool m_isPM;
};

#endif /* _CLOCK_HPP_ */