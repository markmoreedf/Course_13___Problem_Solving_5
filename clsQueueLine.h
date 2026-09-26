#pragma once
#include <queue>
#include <stack>
#include <iostream>
#include "clsDate.h"
using namespace std;

class clsQueueLine
{
private:

    class clsTicket
    {
        string _code = "";
        string _issueTime = "";
        short _averageServeTime = 0;
        short _expectedServeTime = 0;
        short _waitingClients = 0;

    public:
        clsTicket(string code, short averageServeTime, short expectedServeTime, short waitingClients)
        {
            _code = code;
            _issueTime = clsDate::GetCurrentDateTimeString();
            _averageServeTime = averageServeTime;
            _expectedServeTime = expectedServeTime;
            _waitingClients = waitingClients;
        }
        // Setters

        void SetCode(string code) { _code = code; }
        void SetEstTime(int estTimeInMinutes) { _expectedServeTime = estTimeInMinutes; }

        // Getters
        string GetCode() const { return _code; }
        short GetEstTime() const { return _expectedServeTime; }

        __declspec(property(get = GetCode, put = SetCode)) string code;
        __declspec(property(get = GetEstTime, put = SetEstTime)) short expectedServeTime;

        void PrintTicket() const
        {
            string shiftRight = "                    ";

            cout << shiftRight  << endl;
            cout << shiftRight << "-----------------------------\n";
            cout << shiftRight << "\t\t" << _code << "\n";
            cout << shiftRight << "Issued at:  " << _issueTime <<  "\n";
            cout << shiftRight << "Waiting Clients :  " << _waitingClients <<  "\n";
            cout << shiftRight << "Estimated Time: " << _expectedServeTime << endl;
            cout << shiftRight << "-----------------------------\n";
            cout << shiftRight  << endl;
        }


    };

    string _prefix;
    short _AverageServeTime;
    int _totalTickets = 0;


    queue <clsTicket> QueueLine;

public:
    clsQueueLine(string prefix, int averageServeTime) : _prefix(prefix), _AverageServeTime(averageServeTime) {}

    void IssueTicket()
    {
        short clients = QueueLine.size();
        clsTicket t = clsTicket(_prefix + to_string(++_totalTickets), _AverageServeTime, short(_AverageServeTime * clients), clients);
        QueueLine.push(t);
    }

    int WaitingClients() const
    {
        return QueueLine.size();
    }

    string WhoIsNext() const
    {
        return (QueueLine.empty() ? "No Clients Left." : QueueLine.front().code);
    }

    bool ServeNextClient()
    {
        if (QueueLine.empty())
            return false;

        QueueLine.pop();
        return true;
    }

    short ServedClients()
    {
        return _totalTickets - QueueLine.size();
    }

    void PrintQLineLTR() const
    {
        if (QueueLine.empty()) return;

        queue <clsTicket> tempQueue = QueueLine;

        while (tempQueue.size() > 1)
        {
            cout << tempQueue.front().code << " -> ";
            tempQueue.pop();
        }

        cout << tempQueue.front().code;
        tempQueue.pop();
    }

    void PrintQLineRTL() const
    {
        if (QueueLine.empty()) return;

        queue <clsTicket> tempQueue = QueueLine;
        stack <clsTicket> tempStack;

        while (!tempQueue.empty())
        {
            tempStack.push(tempQueue.front());
            tempQueue.pop();
        }

        while (tempStack.size() > 1)
        {
            cout << tempStack.top().code << " <- ";
            tempStack.pop();
        }
        cout << tempStack.top().code;
        tempStack.pop();
    }

    void PrintQueueInfo() const
    {
        string shiftRight = "                    ";
        int currentClients = QueueLine.size();
        cout << shiftRight << "-----------------------------\n";
        cout << shiftRight << "Prefix          =  "  << _prefix << "\n";
        cout << shiftRight << "Total Clients   =  "  << _totalTickets << "\n";
        cout << shiftRight << "Served Clients  =  "  << _totalTickets - currentClients << "\n";
        cout << shiftRight << "Waiting Clients =  "  << currentClients << "\n";
        cout << shiftRight << "-----------------------------\n";
    }

    void PrintAllTickets() const
    {
        queue <clsTicket> tempQueue = QueueLine;

        while (!tempQueue.empty())
        {
            tempQueue.front().PrintTicket();
            tempQueue.pop();
        }
 
    }

};

