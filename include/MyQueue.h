#pragma once
#include "DblLinkedList.h"
template <typename T>
class MyQueue
{
protected:
    DblLinkedList<T> _list;

public: 

    void Print()
    {
        _list.Print();
    }

    // Getters
    T Front() const { return _list.GetItemByIndex(0); }
    T Back()  const { return _list.GetItemByIndex(_list.Size() - 1); }

    T GetItemByIndex(int index) const { return _list.GetItemByIndex(index); }

    int Size() const { return _list.Size(); }


    // Core
    void Push(T value) { _list.InsertAtEnd(value); }
    void Pop() { _list.DeleteFirstNode(); }

    // Utility
    bool IsEmpty()  const { return _list.IsEmpty(); }

    void Reverse() { _list.Reverse(); }

    void UpdateItemByIndex(int index, T newValue) { _list.UpdateItemByIndex(index, newValue); }

    // Insertion
    void InsertAtFront(T value) {  _list.InsertAtBeginning(value); }
    void InsertAtBack(T value) {  _list.InsertAtEnd(value); }
    bool InsertAfterIndex(int index, T valueToInsert) { return _list.InsertAfterIndex(index, valueToInsert); }

    // Deletion
    void Clear() { _list.Clear(); }
};

