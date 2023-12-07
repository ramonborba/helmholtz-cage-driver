/**
 * \file CurrentSensor.cpp
 * 
 * \brief CurrentSensor class implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 06-12-2023
 */

#include "CurrentSensor.hpp"

idf::I2CMaster m_i2c { idf::I2CNumber::I2C0(), idf::SCL_GPIO(22), idf::SDA_GPIO(23), idf::Frequency(400000) };

CurrentSensor::CurrentSensor(idf::I2CAddress t_addr) : m_addr { t_addr } {
}

CurrentSensor::~CurrentSensor()
{
}

uint32_t CurrentSensor::Read() {
    return 0;
}