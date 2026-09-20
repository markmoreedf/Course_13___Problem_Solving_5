#pragma once
#include "MyQueue.h"
#include <string>

using namespace std;

class Ticket
{
public:
    string code;
    int estTime;
    Ticket(string c, int t) :code(c), estTime(t) {}

};


class QueueLine
{
private:
    MyQueue <Ticket> _Line;
    string _prefix;
    int _estTime;

public:
    QueueLine(string prefix, int estTime): _prefix(prefix), _estTime(estTime) {}
    
    void IssueTicket()
    {
        int counter = _Line.Size();
        Ticket t = Ticket(_prefix + to_string(counter), _estTime * counter);
        _Line.Push(t);
    }

    //void PrintQLine()
    //{
    //    for (Ticket& t : _Line)
    //    {
    //        
    //        std::cout << t.code " -> ";
    //    }
    } 

};

