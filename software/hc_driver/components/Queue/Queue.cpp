/**
 * \file Queue.cpp
 * 
 * \brief Queue class implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 15-11-2023
 */

#include "Queue.hpp"

#include "esp_err.h"

template<typename T>
Queue<T>::Queue() : m_pStart ( nullptr ), m_pEnd ( nullptr )
{
}

template<typename T>
Queue<T>::~Queue()
{
    while (!IsEmpty())
    {
        Node<T>* aux = m_pStart;
        m_pStart = m_pStart->pNext;
        delete aux;
    }
}

template<typename T>
esp_err_t Queue<T>::Enqueue(Node<T> t_Node) {
    Node<T>* auxNode = new Node<T>();
    if (auxNode == nullptr) {
        return ESP_ERR_NO_MEM;
    }
    *auxNode = t_Node;
    if (m_pStart == nullptr) {
        m_pStart = auxNode;
        m_pEnd = m_pStart;
    }
    else {
        m_pEnd->pNext = auxNode;
        m_pEnd = auxNode;
    }

    return ESP_OK;
}

template<typename T>
Node<T> Queue<T>::Dequeue() {
    Node<T> auxNode = *m_pStart;
    Node<T>* auxPtr = m_pStart;
    m_pStart = m_pStart->pNext;
    delete auxPtr;
    return auxNode;
}

template<typename T>
bool Queue<T>::IsEmpty() {
    return m_pStart == nullptr;
}
