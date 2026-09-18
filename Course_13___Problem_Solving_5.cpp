#include <iostream>
#include "clsDblLinkedList.h"
#include "ClsMyQueue.h"
#include <string>

using namespace std;

void TestDblLinkedList()
{
    clsDblLinkedList<int> list;

    std::cout << "===========================================\n";
    std::cout << "1. UTILITY & EMPTY LIST CHECKS\n";
    std::cout << "===========================================\n";

    std::cout << "Is empty? " << (list.IsEmpty() ? "Yes" : "No") << "\n";
    std::cout << "Current Size: " << list.Size() << "\n";
    std::cout << "Print Empty: ";
    list.Print();

    std::cout << "\n===========================================\n";
    std::cout << "2. TESTING INSERTIONS & OVERLOADS\n";
    std::cout << "===========================================\n";

    // 2.1 Insert at beginning & end
    list.InsertAtBeginning(20);
    list.InsertAtBeginning(10);
    list.InsertAtEnd(40);
    std::cout << "List after [10, 20, 40]: ";
    list.Print(); // 10 20 40

    // 2.2 InsertAfter (by Node pointer)
    clsDblLinkedList<int>::Node* node20 = list.FindByValue(20);
    list.InsertAfterNode(node20, 30);
    std::cout << "Insert 30 after Node(20): ";
    list.Print(); // 10 20 30 40

    // 2.3 InsertAfter (by Value)
    list.InsertAfterValue(30, 35);
    std::cout << "Insert 35 after Value 30: ";
    list.Print(); // 10 20 30 35 40

    // 2.4 InsertAfter (by Index)
    list.InsertAfterIndex(0, 15);
    std::cout << "Insert 15 after Index 0:  ";
    list.Print(); // 10 15 20 30 35 40

    // 2.5 Edge Cases: Invalid InsertAfter
    std::cout << "\nEdge Case: InsertAfter invalid value 99: "
        << (list.InsertAfterIndex(99, 100) ? "Success" : "Failed (Expected)") << "\n";
    std::cout << "Edge Case: InsertAfter out-of-bounds index 100: "
        << (list.InsertAfterIndex(100, 500) ? "Success" : "Failed (Expected)") << "\n";

    std::cout << "\n===========================================\n";
    std::cout << "3. SEARCHING & GETTING DATA\n";
    std::cout << "===========================================\n";

    std::cout << "Item at Index 0: " << list.GetItemByIndex(0) << "\n";
    std::cout << "Item at Index 3: " << list.GetItemByIndex(3) << "\n";
    std::cout << "Find Node by Value 35: " << (list.FindByValue(35) != nullptr ? "Found" : "Not Found") << "\n";
    std::cout << "Find Node by Value 999: " << (list.FindByValue(999) != nullptr ? "Found" : "Not Found") << "\n";

    std::cout << "\n===========================================\n";
    std::cout << "4. UPDATING DATA\n";
    std::cout << "===========================================\n";

    list.UpdateItemByIndex(1, 12);
    std::cout << "Updated Index 1 to 12: ";
    list.Print();

    std::cout << "Edge Case: Update invalid index 50: "
        << (list.UpdateItemByIndex(50, 99) ? "Success" : "Failed (Expected)") << "\n";

    std::cout << "\n===========================================\n";
    std::cout << "5. REVERSING THE LIST\n";
    std::cout << "===========================================\n";

    std::cout << "Original: ";
    list.Print();
    list.Reverse();
    std::cout << "Reversed: ";
    list.Print();
    list.Reverse(); // Reverse back to original order
    std::cout << "Restored: ";
    list.Print();

    std::cout << "\n===========================================\n";
    std::cout << "6. DELETIONS & EDGE CASES\n";
    std::cout << "===========================================\n";

    // Delete First & Last
    list.DeleteFirstNode();
    std::cout << "Deleted First Node: ";
    list.Print();

    list.DeleteLastNode();
    std::cout << "Deleted Last Node:  ";
    list.Print();

    // Delete by Value
    list.DeleteNodeByValue(20);
    std::cout << "Deleted Value 20:   ";
    list.Print();

    // Delete by Index
    list.DeleteNodeByIndex(1);
    std::cout << "Deleted Index 1:    ";
    list.Print();

    // Delete by Node pointer
    clsDblLinkedList<int>::Node* targetNode = list.FindByIndex(0);
    list.DeleteNode(targetNode);
    std::cout << "Deleted Node at Index 0: ";
    list.Print();

    std::cout << "Size after deletions: " << list.Size() << "\n";

    std::cout << "\n===========================================\n";
    std::cout << "7. CLEARING & DESTROYING\n";
    std::cout << "===========================================\n";

    list.Clear();
    std::cout << "Cleared entire list.\n";
    std::cout << "Is empty? " << (list.IsEmpty() ? "Yes" : "No") << "\n";
    std::cout << "Size: " << list.Size() << "\n";

    std::cout << "\n===========================================\n";
    std::cout << "ALL TESTS COMPLETED SUCCESSFULLY!\n";
    std::cout << "===========================================\n";

}

void TestMyQueue()
{
    ClsMyQueue<int> myQueue;

    myQueue.Push(10);
    myQueue.Push(20);
    myQueue.Push(30);
    myQueue.Push(40);
    myQueue.Push(50);
    myQueue.Push(60);

    cout << "\nQueue Size: " << myQueue.Size() << "\n";

    cout << "\nQueue Elements: ";     
    myQueue.Print();

    cout << "\nFront: " << myQueue.Front() << ", Back: " << myQueue.Back() << "\n";

    myQueue.Pop();
    myQueue.Pop(); 
    myQueue.Pop();

    cout << "\n\nQueue Elements after Popping 3 items: "; 
    myQueue.Print();

    cout << "\nFront: " << myQueue.Front() << ", Back: " << myQueue.Back() << "\n";
    
    cout << "\n\nGet item By index 0: " << myQueue.GetItemByIndex(0) << endl;

    cout << "\n\nReverse the Queue: "; myQueue.Reverse();
    myQueue.Print();

    cout << "\n\nUpdate item at index 1 to 100: "; myQueue.UpdateItemByIndex(1, 100);
    myQueue.Print();

    cout << "\n\nInsert 5 at front: "; myQueue.InsertAtFront(5);
    myQueue.Print();

    cout << "\n\nInsert 70 at back: "; myQueue.InsertAtBack(70);
    myQueue.Print();
}

int main()
{
    TestMyQueue();
   
    return 0;
}

