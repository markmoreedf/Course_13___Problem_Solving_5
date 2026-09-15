#pragma once

template <typename T>
class clsDblLinkedList
{
private:
    int _size = 0;
public:
    class Node
    {
    public:
        T value;
        Node* next;
        Node* prev;
        Node() : value(T()), next(nullptr), prev(nullptr) {}
        Node(T val) : value(val), next(nullptr), prev(nullptr) {}
    };

    Node* head = nullptr;

    Node* FindNode(T value)
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->value == value)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void PrintLinkedList()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->value << "  ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ////////// Insertion //////////
    void InsertAtBeginning(T value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr)
        {
            head->prev = newNode;
        }

        head = newNode;
        _size++;
    }

    void InsertAfter(Node* prevNode, T valueToInsert)
    {
        if (prevNode == nullptr)
        {
            std::cout << "Previous node cannot be NULL\n";
            return;
        }

        Node* n = new Node(valueToInsert);
        n->next = prevNode->next;
        n->prev = prevNode;
        if (prevNode->next != nullptr)
        {
            prevNode->next->prev = n;
        }
        prevNode->next = n;
        _size++;
    }

    void InsertAtEnd(T value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        _size++;
    }

    ////////// Deletion //////////
    void DeleteLinkedList()
    {
        while (head != nullptr)
        {
            Node* tempPtr = head;
            head = head->next;
            delete (tempPtr);
        }
        _size = 0;
    }

    void DeleteFirstNode()
    {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;

        if (head != nullptr) head->prev = nullptr;

        delete temp;
        _size--;
    }

    void DeleteLastNode()
    {
        if (head == nullptr) return;

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head->next;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        delete temp;
        _size--;
    }

    void DeleteNode(T valueToDelete)
    {
        if (head == nullptr) return;

        Node* temp = head;
        if (head->value == valueToDelete)
        {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            delete temp;
            return;
        }

        while (temp != nullptr)
        {
            if (temp->value == valueToDelete)
            {
                temp->prev->next = temp->next;
                if (temp->next != nullptr)
                {
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
        _size--;
    }

    void DeleteNode(Node* nodeToDelete)
    {
        // check if Node belongs to this list 
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp == nodeToDelete) { break; }
            temp = temp->next;
        }
        if (temp == nullptr) { return; }

        if (head == nullptr || nodeToDelete == nullptr) { return; }

        if (head == nodeToDelete) { head = nodeToDelete->next; }

        if (nodeToDelete->prev != nullptr) { nodeToDelete->prev->next = nodeToDelete->next; }

        if (nodeToDelete->next != nullptr) { nodeToDelete->next->prev = nodeToDelete->prev; }

        delete nodeToDelete;

        _size--;
        
    }

    void DeleteNodeByIndex(int index)
    {
        if (index < 0) return;

        if (head == nullptr) return;

        if (index == 0)
        {
            DeleteFirstNode();
            return;
        }

        Node* temp = head;
        int counter = 0;

        while (counter < index)
        {
            temp = temp->next;
            if (temp == nullptr)
                return;
            counter++;
        }

        temp->prev->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;

        delete temp;

        _size--;

    }

    ////////// utility functions //////////

    int Size()
    {
        return _size;
    }

    bool IsEmpty()
    {
        return _size == 0;
    }


};

