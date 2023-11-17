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

protected:
    int m_day;
    int m_month;
    int m_year;
};

#endif /* _CALENDAR_HPP_ */