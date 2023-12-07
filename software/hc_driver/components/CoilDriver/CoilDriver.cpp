/**
 * \file CoilDriver.cpp
 * 
 * \brief CoilDriver class implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 06-12-2023
 */

#include "CoilDriver.hpp"

CoilDriver::CoilDriver(idf::GPIONum t_SourcePin, idf::I2CAddress t_addr) :
    m_Source { t_SourcePin },
    m_Sensor { t_addr } {
}

CoilDriver::~CoilDriver()
{
}

void CoilDriver::SetSource(uint32_t t_Value) {
    m_Source.SetValue(t_Value);
}

uint32_t CoilDriver::ReadCurrent() {
    return m_Sensor.Read();
}