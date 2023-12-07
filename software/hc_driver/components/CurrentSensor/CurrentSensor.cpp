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

CurrentSensor::CurrentSensor(idf::I2CNumber t_num, idf::SCL_GPIO t_scl, idf::SDA_GPIO t_sda, idf::Frequency t_freq) : m_i2c { t_num, t_scl, t_sda, t_freq } {
}

CurrentSensor::~CurrentSensor()
{
}

uint32_t CurrentSensor::Read() {
    return 0;
}