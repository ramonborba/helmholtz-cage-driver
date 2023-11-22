/**
 * \file Calendar.hpp
 * 
 * \brief Calendar class header file
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 17-11-2023
 */

#ifndef _CALENDAR_HPP_
#define _CALENDAR_HPP_

class Calendar {
public:
    Calendar(int t_day, int t_month, int t_year);
    ~Calendar();
    void setCalendar(int t_day, int t_month, int t_year);
    void readCalendar(int& t_day, int& t_month, int& t_year);
    void advance();

    friend bool operator< (Calendar& l, Calendar&r) {
        if (l.m_year < r.m_year) {
            if (l.m_month < r.m_month){
                if (l.m_day < r.m_day) {
                    return true;
                }
            }
        }
        else {
            return false;
        }
    }

    friend bool operator== (Calendar& l, Calendar& r) {
        return (l.m_year == r.m_year) && (l.m_month == r.m_month) && (l.m_day == r.m_day);
    }

    friend bool operator> (Calendar& l, Calendar& r) {
        return !(l == r) && !(l < r);
    }

    friend bool operator<= (Calendar& l, Calendar& r) {
        return (l == r) || (l < r);
    }

    friend bool operator>= (Calendar& l, Calendar& r) {
        return (l == r) && (l > r);
    }

    friend bool operator!= (Calendar& l, Calendar& r) {
        return !(l == r);
    }

protected:
    int m_day;
    int m_month;
    int m_year;
};

#endif /* _CALENDAR_HPP_ */