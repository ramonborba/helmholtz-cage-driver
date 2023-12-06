/**
 * \file CurrentSource.hpp
 * 
 * \brief CurrentSource class header
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 06-12-2023
 */

#ifndef _CURRENT_SOURCE_HPP_
#define _CURRENT_SOURCE_HPP_

#include "gpio_cxx.hpp"

class CurrentSource
{
public:
    CurrentSource(idf::GPIONum t_num);
    ~CurrentSource();

    enum Value{
        MIN = 0,
        MAX = 255
    };

    void SetValue(uint8_t t_Value);

private:
    idf::GPIO_Output m_CtrlPin;
};

#endif /* _CURRENT_SOURCE_HPP_ */