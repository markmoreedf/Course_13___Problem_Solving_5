#pragma once
template <typename T>
class DynamicArray
{
protected:
    int _size = 0;
public:
    T* _data = nullptr;

    DynamicArray(int size = 0)
    {
        if (size < 0) size = 0;
        _size = size;
        _data = new T[_size];
    }

    ~DynamicArray() 
    {
        delete[] _data;
    }

    void Print() const
    {
        for (int i = 0; i < _size; i++)
        {
            std::cout << _data[i] << "  ";
        }
        std::cout << std::endl;
    }

    int Size() const { return _size; }

    bool IsEmpty() const { return (_size == 0); }

    bool SetItem(int index, T value)
    {
        if (index < 0 || index >= _size) return false;
        _data[index] = value;
        return true;
    }

    T GetItem(int index) const
    {
        if (index < 0 || index >= _size) return T();
        return _data[index];
    }

    void Resize(int newSize)
    {
        if (newSize < 0) newSize = 0;
        T* tempArray = new T[newSize];

        if (newSize < _size)
            _size = newSize;

        for(int i =0; i < _size; i++)
        {
            tempArray[i] = _data[i];
        }

        delete[] _data;
        _data = tempArray;
        _size = newSize;
    }

    void Reverse()
    {
        for (int i = 0; i < _size/2; i++)
        {
            T temp = _data[i];
            _data[i] = _data[_size - 1 - i];
            _data[_size - 1 - i] = temp;
        }
    }

    void Clear()
    {
        delete[] _data;
        _data = nullptr;
        _size = 0;
    }

    bool UpdateItemByIndex(int index, T value)
    {
        if (index < 0 || index >= _size) return false;
        _data[index] = value;
        return true;
    }

    bool DeleteItemByIndex(int index)
    {
        if (index < 0 || index >= _size) return false;
        T* tempArray = new T[_size - 1];
        for (int i = 0, j = 0; i < _size; i++)
        {
            if (i != index)
            {
                tempArray[j++] = _data[i];
            }
        }
        delete[] _data;
        _data = tempArray;
        _size--;
        return true;
    }

    bool DeleteItemByValue(T value)
    {
        int index = FindIndexByValue(value);

        if (index == -1) return false;

        return DeleteItemByIndex(index);
    }

    void DeleteFirstItem()
    {
        DeleteItemByIndex(0);
    }

    void DeleteLastItem()
    {
        DeleteItemByIndex(_size - 1);
    }

    int FindIndexByValue(T value) const
    {
        for (int i = 0; i < _size; i++)
        {
            if (_data[i] == value)
            {
                return i;
            }
        }
        return -1; // Not found
    }

    bool InsertAt(int index, T value)
    {
        if (index < 0 || index > _size) return false;

        _size++;
        T* tempArray = new T[_size];

        for( int i =0; i < index; i++)
        {
            tempArray[i] = _data[i];
        }

        tempArray[index] = value;

        for (int i = index; i < _size - 1; i++)
        {
            tempArray[i + 1] = _data[i];
        }

        delete[] _data;
        _data = tempArray;
        return true;
    }
    bool InsertBefore(int index, T value)
    {
        if (index < 1)
            return InsertAt(0, value);
        
        return InsertAt(index-1, value);
    }
    bool InsertAfter(int index, T value)
    {
        if (index >= _size)
        {
            return InsertAt(_size - 1, value);
        }
        return InsertAt(index + 1, value);
    }

    void InsertAtBeginning(T value)
    {
        InsertAt(0, value);
    }

    void InsertAtEnd(T value)
    {
        InsertAt(_size, value);
    }

};

