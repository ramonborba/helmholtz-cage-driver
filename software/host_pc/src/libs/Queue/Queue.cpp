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
#include <iostream>

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
int Queue<T>::Enqueue(T t_Data) {
    Node<T>* auxNode = new Node<T>(t_Data);
    if (auxNode == nullptr) {
        return 1;
    }
    auxNode->data =  t_Data;
    if (m_pStart == nullptr) {
        m_pStart = auxNode;
        m_pEnd = m_pStart;
    }
    else {
        m_pEnd->pNext = auxNode;
        m_pEnd = auxNode;
    }

    return 0;
}

template<typename T>
T Queue<T>::Dequeue() {
    T data = m_pStart->data;
    Node<T>* auxPtr = m_pStart;
    m_pStart = m_pStart->pNext;
    delete auxPtr;
    return data;
}

template<typename T>
bool Queue<T>::IsEmpty() {
    return m_pStart == nullptr;
}

template<typename T>
void Queue<T>::ListAll() {
    Node<T>* view = m_pStart;
    while (view)
    {
        std::cout << view->data << "\n";
        view = view->pNext;
    }
}

template<typename T>
void Queue<T>::ListInterval(ClockCalendar t_inStart, ClockCalendar t_inEnd) {
    Node<T>* view = m_pStart;
    while ((view))
    {
        if ((view->data > t_inStart) && (view->data < t_inEnd)) {
            std::cout << view->data << "\n";
        }
        view = view->pNext;
    }
}