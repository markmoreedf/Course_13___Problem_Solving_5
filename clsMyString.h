#pragma once

#include<string>
#include "MyStackArr.h"

using namespace std;

class clsMyString
{
private:
    MyStackArr<string> _undoStack;
    MyStackArr<string> _redoStack;
    string _value = "";

public:
    // Setters
    void SetValue(string value)
    {
        _undoStack.Push(_value);
        _value = value;
        _redoStack.Clear(); // Clear redo stack on new action
    }
    // Getters
    string GetValue() const { return _value; }

    void Print() const { cout << _value << endl; }

    void PrintHistory() { _undoStack.Print(); }

    // Core
    void Undo()
    {
        if (_undoStack.IsEmpty())
        {
            cout << "No more history to undo." << endl;
            return;
        }
        _redoStack.Push(_value);
        _value = _undoStack.Top();
        _undoStack.Pop();
    }

    void Redo()
    {
        if (_redoStack.IsEmpty())
        {
            cout << "No more history to redo." << endl;
            return;
        }
        _undoStack.Push(_value);
        _value = _redoStack.Top();
        _redoStack.Pop();
    }

};

