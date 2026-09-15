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


    ///////// Searching //////////

    Node* FindByValue(T value)
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

    Node* FindByIndex(int index)
    {
        if (index < 0 || index >= _size) { return nullptr; }
        Node* temp = head;
        while (index > 0)
        {
            temp = temp->next;
            index--;
        }
        return temp;

    }

    T GetItemByIndex(int index)
    {
        Node* node = FindByIndex(index);
        if (node != nullptr) { return node->value; }

        //Index out of bounds
        return T();

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

    bool InsertAfterNode(Node* prevNode, T valueToInsert)
    {
        if (prevNode == nullptr)
        {
            std::cout << "Previous node cannot be NULL\n";
            return false;
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
        return true;
    }

    bool InsertAfterValue(T valueToFind, T valueToInsert)
    {
        Node* temp = FindByValue(valueToFind);
        // to prevent calling InsertAfter with a nullptr, we check if temp is nullptr
        if (temp == nullptr) return false;
        return InsertAfterNode(temp, valueToInsert);
    }

    bool InsertAfterIndex(int index, T valueToInsert)
    {
        Node* temp = FindByIndex(index);

        // to prevent calling InsertAfter with a nullptr, we check if temp is nullptr
        if (temp == nullptr) return false;

        return InsertAfterNode(temp, valueToInsert);
    }

    void InsertAtEnd(T value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            _size++;
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
            _size--;
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

    void DeleteNode(Node* nodeToDelete)
    {
        // check if Node belongs to this list 
        //its safe but it trades performance for safety

        //Node* temp = head;
        //while (temp != nullptr)
        //{
        //    if (temp == nodeToDelete) { break; }
        //    temp = temp->next;
        //}
        //if (temp == nullptr) { return; }

        if (head == nullptr || nodeToDelete == nullptr) { return; }

        if (head == nodeToDelete) { head = nodeToDelete->next; }

        if (nodeToDelete->prev != nullptr) { nodeToDelete->prev->next = nodeToDelete->next; }

        if (nodeToDelete->next != nullptr) { nodeToDelete->next->prev = nodeToDelete->prev; }

        delete nodeToDelete;

        _size--;

    }

    void DeleteNodeByValue(T valueToDelete)
    {
        if (head == nullptr) return;
        DeleteNode(FindByValue(valueToDelete));
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

        DeleteNode(FindByIndex(index));
    }


    ////////// utility functions //////////

    int Size() { return _size; }

    bool IsEmpty() { return _size == 0; }

    void Clear()
    {
        while (head != nullptr)
        {
            Node* tempPtr = head;
            head = head->next;
            delete (tempPtr);
        }
        _size = 0;
    }

    void Reverse()
    {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) { head = temp->prev; }

    }


    ////////// Updating //////////

    bool UpdateItemByIndex(int index, T newValue)
    {
        Node* node = FindByIndex(index);
        if (node != nullptr)
        {
            node->value = newValue;
            return true;
        }
        return false;
    }


    ~clsDblLinkedList() { Clear(); }
};

