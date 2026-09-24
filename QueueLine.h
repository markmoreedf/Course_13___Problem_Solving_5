#pragma once
#include "MyQueue.h"
#include <string>
#include <iostream>
#include "clsDate.h"
using namespace std;

class Ticket
{
    string _code;
    int _estTime;
public:
    Ticket() :_code(""), _estTime(0) {}
    Ticket(string c, int t) :_code(c), _estTime(t) {}
    // Setters
    
    void SetCode(string code) { _code = code; }
    void SetEstTime(int estTimeInMinutes) { _estTime = estTimeInMinutes; }

    // Getters
    string GetCode() const { return _code; }
    int GetEstTime() const { return _estTime; }

    __declspec(property(get = GetCode, put = SetCode)) string code;
    __declspec(property(get = GetEstTime, put = SetEstTime)) int estTime;

    void PrintTicket() const
    {
        string shiftRight = "                    ";
        
        cout << shiftRight << "-----------------------------\n";
        cout << shiftRight << "\t\t" << _code << "\n";
        cout << shiftRight << "Issued at:  " << clsDate::GetCurrentDateTimeString() << "\n";
        cout << shiftRight << "Estimated Time: " << _estTime << endl;
        cout << shiftRight << "-----------------------------\n";
    }


};


class QueueLine
{
private:
    MyQueue <Ticket> _Line;
    string _prefix;
    int _estTime;
    int totalTickets = 0;

public:
    QueueLine(string prefix, int estTime) : _prefix(prefix), _estTime(estTime) {}

    void IssueTicket()
    {
        totalTickets++;
        Ticket t = Ticket( _prefix + to_string(totalTickets) ,  _estTime * (_Line.Size() + 1) );
        _Line.Push(t);
    }

    void ServeNextClient()
    {
        _Line.Pop();
        

    }

    void PrintQLine() const
    {
        for (int i = 0; i < _Line.Size() -1 ; i++)
        {
            std::cout << _Line.GetItemByIndex(i).code << " -> ";
        }
        std::cout << _Line.Back().code << endl; 
    }

    void PrintQueueInfo() const
    {
        string shiftRight = "                    ";
        int currentClients = _Line.Size();
        cout << shiftRight << "-----------------------------\n";
        cout << shiftRight << "Prefix          =  "  << _prefix << "\n";
        cout << shiftRight << "Total Clients   =  "  << totalTickets << "\n";
        cout << shiftRight << "Served Clients  =  "  << totalTickets - currentClients << "\n";
        cout << shiftRight << "Waiting Clients =  "  << currentClients << "\n";
        cout << shiftRight << "-----------------------------\n";
    }

    void PrintAllTickets() const
    {
        for (int i = 0; i < _Line.Size(); i++)
        {
            std::cout << "                       Tickets\n";
            _Line.GetItemByIndex(i).PrintTicket();
            std::cout << endl << endl;
        }
 
    }

};

