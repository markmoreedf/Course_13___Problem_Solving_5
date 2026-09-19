#pragma once

template <typename T>
class DblLinkedList
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
        Node(T val, Node* nextNode, Node* prevNode) : value(val), next(nextNode), prev(prevNode) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;

    void Print() const
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

    Node* FindByValue(T value) const
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

    Node* FindByIndex(int index) const
    {
        if (index < 0 || index >= _size) { return nullptr; }
        if (index == _size - 1 ) { return tail; }
        Node* temp = head;
        while (index > 0)
        {
            temp = temp->next;
            index--;
        }
        return temp;

    }

    T GetItemByIndex(int index) const
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

        if (head != nullptr) head->prev = newNode;
        else tail = newNode;

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
        if(tail == nullptr) // If the list is empty, insert at the beginning
        {
            InsertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value,nullptr,tail);
        tail->next = newNode;
        tail = newNode;
        _size++;
    }

    ////////// Deletion //////////

    void DeleteFirstNode()
    {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;

        if (head != nullptr) head->prev = nullptr;
        else tail = nullptr; // If the list becomes empty, update tail to nullptr
        delete temp;
        _size--;
    }

    void DeleteLastNode()
    {
        if (tail == nullptr) return;

        if (tail == head)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            _size--;
            return;
        }
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
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

        if (tail == nodeToDelete) { tail = nodeToDelete->prev; }

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

    int Size() const { return _size; }

    bool IsEmpty()  const { return _size == 0; }

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
        if (head == nullptr || head == tail) return;

        Node* current = head;
        Node* temp = nullptr;
        Node* oldHead = head;

        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) { head = temp->prev; }

        tail = oldHead;
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


    ~DblLinkedList() { Clear(); }
};

