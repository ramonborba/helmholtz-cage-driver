/**
 * \file Queue.hpp
 * 
 * \brief Queue class header
 * 
 * Queue implementation, mainly intended to be used as a log for this application
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 15-11-2023
 */
#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include "ClockCalendar.hpp"

template<typename T>
class Queue
{
public:
    Queue();
    ~Queue();

    template<typename U>
    struct Node
    {
        Node<U>* pNext;
        U data;
        Node() : pNext ( nullptr ) {};
        Node(U t_Val) : pNext ( nullptr ), data (t_Val) {}
    };
    
    int Enqueue(T t_Data);

    T Dequeue();

    bool IsEmpty();

    void ListAll();

    void ListInterval(ClockCalendar t_inStart, ClockCalendar t_inEnd);

    Node<T>* GetView() {
        return m_pStart;
    };
private:
    Node<T>* m_pStart;
    Node<T>* m_pEnd;
};

#include "../Queue.cpp"

#endif /* _QUEUE_HPP_ */