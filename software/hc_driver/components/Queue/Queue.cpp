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
Queue<T>::Queue() : m_start ( nullptr ), m_end ( nullptr )
{
}

template<typename T>
Queue<T>::~Queue()
{
    while (!isEmpty())
    {
        Node<T>* aux = m_start;
        m_start = m_start->next;
        delete aux;
    }
}

template<typename T>
esp_err_t Queue<T>::Enqueue(Node<T> newNode) {
    Node<T>* auxNode = new Node<T>();
    if (auxNode == nullptr) {
        return ESP_ERR_NO_MEM;
    }
    *auxNode = newNode;
    if (m_start == nullptr) {
        m_start = auxNode;
        m_end = m_start;
    }
    else {
        m_end->next = auxNode;
        m_end = auxNode;
    }

    return ESP_OK;
}

template<typename T>
Node<T> Queue<T>::Dequeue() {
    Node<T> auxNode = *m_start;
    Node<T>* auxPtr = m_start;
    m_start = m_start->next;
    delete auxPtr;
    return auxNode;
}

template<typename T>
bool Queue<T>::isEmpty() {
    return m_start == nullptr;
}
