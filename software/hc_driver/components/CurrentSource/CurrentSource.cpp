/**
 * \file CurrentSource.cpp
 * 
 * \brief CurrentSource class implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 06-12-2023
 */

#include "CurrentSource.hpp"


CurrentSource::CurrentSource(idf::GPIONum t_num) : m_CtrlPin { t_num } {
    m_CtrlPin.set_low();
}

CurrentSource::~CurrentSource() {
}

void CurrentSource::SetValue(uint8_t t_Value) {
    if (t_Value) {
        m_CtrlPin.set_high();
    }
    else {
        m_CtrlPin.set_low();
    }
}