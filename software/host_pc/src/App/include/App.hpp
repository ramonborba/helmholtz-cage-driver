/**
 * \file App.hpp
 * 
 * \brief Application class responsible for implementing the application logic
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 20-11-2023
 */

#pragma once

class Application
{
public:
    static void Start();
private:
    Application()  = default;

    static Application m_Host;
};