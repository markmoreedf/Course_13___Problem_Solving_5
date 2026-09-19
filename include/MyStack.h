#pragma once
#include "MyQueue.h"
template <typename T>
class MyStack : public MyQueue<T>
{
public:

    T Top() const { return this->_list.tail->value; }

    T Bottom() const { return this->_list.head->value; }

    void Pop() { this->_list.DeleteLastNode(); }

};

