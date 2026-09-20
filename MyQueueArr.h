#pragma once
#include "DynamicArray.h"
template <typename T>
class MyQueueArr
{
protected:
    DynamicArray<T> _qArray;

public:
    void Print() { _qArray.Print(); }

    // Getters
    T Front() const { return _qArray.GetItem(0); }
    T Back()  const { return _qArray.GetItem(_qArray.Size() - 1); }

    T GetItem(int index) const { return _qArray.GetItem(index); }

    int Size() const { return _qArray.Size(); }

    // Core
    void Push(T value) { _qArray.InsertAtEnd(value); }
    void Pop() { _qArray.DeleteFirstItem(); }

    // Utility
    bool IsEmpty()  const { return _qArray.IsEmpty(); }

    void Reverse() { _qArray.Reverse(); }
    void UpdateItemByIndex(int index, T newValue) { _qArray.UpdateItemByIndex(index, newValue); }

    // Insertion
    void InsertAtFront(T value) { _qArray.InsertAtBeginning(value); }
    void InsertAtBack(T value) { _qArray.InsertAtEnd(value); }
    bool InsertAfterIndex(int index, T valueToInsert) { return _qArray.InsertAfter(index, valueToInsert); }

    // Deletion
    void Clear() { _qArray.Clear(); }







};

