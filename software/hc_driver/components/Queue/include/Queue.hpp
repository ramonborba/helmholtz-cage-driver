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

#include "esp_err.h"

template <typename T>
struct Node
{
    Node<T>* pNext { nullptr };
    T data;
    Node() = default;
    Node(T t_Val) : data (t_Val) {}
};

template<typename T>
class Queue
{
private:
    Node<T>* m_pStart;
    Node<T>* m_pEnd;
public:
    Queue();
    ~Queue();
    
    esp_err_t Enqueue(Node<T> t_Node);

    Node<T> Dequeue();

    bool IsEmpty();
};

#include "../Queue.cpp"

#endif /* _QUEUE_HPP_ */