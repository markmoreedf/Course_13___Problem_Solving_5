#pragma once
#include "MyQueueArr.h"
template <typename T>
class MyStackArr : public MyQueueArr <T>
{
public:
    void Push(T value) { this->_qArray.InsertAtBeginning(value); }

    T Top() const { return this->Front(); }

    T Bottom() const { return this->Back(); }

};

