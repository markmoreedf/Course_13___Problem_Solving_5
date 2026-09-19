#pragma once
#include "MyQueue.h"
template <typename T>
class MyStack : public MyQueue<T>
{
public:

    void Push(T value) { this->_list.InsertAtBeginning(value); }

    T Top() const { return this->Front(); }

    T Bottom() const { return this->Back(); }

    

};

