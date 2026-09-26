#include <iostream>
#include "DblLinkedList.h"
#include "MyQueue.h"
#include "MyStack.h"
#include "DynamicArray.h"
#include "MyQueueArr.h"
#include "MyStackArr.h"
#include "clsMyString.h"
#include "clsQueueLine.h"
using namespace std;

static void TestDblLinkedList()
{
    DblLinkedList<int> list;
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
    DblLinkedList<int>::Node* node20 = list.FindByValue(20);
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
    DblLinkedList<int>::Node* targetNode = list.FindByIndex(0);
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

static void TestMyQueue()
{
    MyQueue<int> myQueue;

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

static void TestMyStack()
{
    MyStack<int> myStack;
    myStack.Push(10);
    myStack.Push(20);
    myStack.Push(30);
    myStack.Push(40);
    myStack.Push(50);
    myStack.Push(60);
    cout << "\nStack Size: " << myStack.Size() << "\n";
    cout << "\nStack Elements: ";     
    myStack.Print();
    cout << "\nTop: " << myStack.Top() << ", Bottom: " << myStack.Bottom() << "\n";
    myStack.Pop();
    myStack.Pop(); 
    myStack.Pop();
    cout << "\n\nStack Elements after Popping 3 items: "; 
    myStack.Print();
    cout << "\nTop: " << myStack.Top() << ", Bottom: " << myStack.Bottom() << "\n";
    
    cout << "\n\nGet item By index 0: " << myStack.GetItemByIndex(0) << endl;
    cout << "\n\nReverse the Stack: "; myStack.Reverse();
    myStack.Print();
    cout << "\n\nUpdate item at index 1 to 100: "; myStack.UpdateItemByIndex(1, 100);
    myStack.Print();
    cout << "\n\nInsert 5 at front: "; myStack.InsertAtFront(5);
    myStack.Print();
    cout << "\n\nInsert 70 at back: "; myStack.InsertAtBack(70);
    myStack.Print();

    cout << "\n\nUpdate item at index 2 to 200: ";
    myStack.UpdateItemByIndex(2, 200);
    myStack.Print();
}

static void TestDynamicArray()
{
    DynamicArray<int> arr(5);
    for (int i = 0; i < arr.Size(); ++i) {
        arr.SetItem(i, i * 10);
    }
    std::cout << "Dynamic Array Elements: ";    arr.Print();
    std::cout << "Size: " << arr.Size() << "\n";

    arr.Reverse();
    std::cout << "\n\nReversed Array Elements: ";
    arr.Print();

    arr.InsertAfter(2, 15);
    std::cout << "\n\nInserted 15 after Index 2: ";
    arr.Print();

    arr.InsertAt(2, 25);
    std::cout << "\n\nInserted 25 at Index 2: ";
    arr.Print();

    arr.InsertBefore(2, 35);
    std::cout << "\n\nInserted 35 before Index 2: ";
    arr.Print();

    arr.InsertAtBeginning(45);
    std::cout << "\n\nInserted 45 at Beginning: ";
    arr.Print();

    arr.InsertAtEnd(-5);
    std::cout << "\n\nInserted -5 at End: ";
    arr.Print();

    arr.UpdateItemByIndex(2, 100);
    std::cout << "\n\nUpdated Index 2 to 100: ";
    arr.Print();

    arr.DeleteItemByIndex(1);
    std::cout << "\n\nDeleted Item at Index 1: ";
    arr.Print();

    arr.DeleteItemByValue(99);
    std::cout << "\n\nDeleted Item with Value 99: ";
    arr.Print();

    arr.DeleteItemByValue(45);
    std::cout << "\n\nDeleted Item with Value 45: ";
    arr.Print();

    arr.Resize(3);
    std::cout << "\n\nResized Array Elements: ";
    arr.Print();
    std::cout << "New Size: " << arr.Size() << "\n";

    arr.Resize(6);
    std::cout << "\n\nResized Array Elements: ";
    arr.Print();
    std::cout << "New Size: " << arr.Size() << "\n";

    arr.Clear();
    arr.Print();
    std::cout << "\n\nCleared Array. Is Empty? " << (arr.IsEmpty() ? "Yes" : "No") << "\n";

}

static void TestMyQueueArr()
{
    MyQueueArr<int> myQueueArr;
    myQueueArr.Push(10);
    myQueueArr.Push(20);
    myQueueArr.Push(30);
    myQueueArr.Push(40);
    myQueueArr.Push(50);
    myQueueArr.Push(60);
    cout << "\nQueue Size: " << myQueueArr.Size() << "\n";
    cout << "\nQueue Elements: ";     
    myQueueArr.Print();
    cout << "\nFront: " << myQueueArr.Front() << ", Back: " << myQueueArr.Back() << "\n";
    myQueueArr.Pop();
    myQueueArr.Pop(); 
    myQueueArr.Pop();
    cout << "\n\nQueue Elements after Popping 3 items: "; 
    myQueueArr.Print();
    cout << "\nFront: " << myQueueArr.Front() << ", Back: " << myQueueArr.Back() << "\n";
    
    cout << "\n\nGet item By index 0: " << myQueueArr.GetItem(0) << endl;
    cout << "\n\nReverse the Queue: "; myQueueArr.Reverse();
    myQueueArr.Print();
    cout << "\n\nUpdate item at index 1 to 100: "; myQueueArr.UpdateItemByIndex(1, 100);
    myQueueArr.Print();
    cout << "\n\nInsert 5 at front: "; myQueueArr.InsertAtFront(5);
    myQueueArr.Print();
    cout << "\n\nInsert 70 at back: "; myQueueArr.InsertAtBack(70);
    myQueueArr.Print();
}

static void TestMyStackArr()
{
    MyStackArr<int> myStackArr;
    myStackArr.Push(10);
    myStackArr.Push(20);
    myStackArr.Push(30);
    myStackArr.Push(40);
    myStackArr.Push(50);
    myStackArr.Push(60);
    cout << "\nStack Size: " << myStackArr.Size() << "\n";
    cout << "\nStack Elements: ";     
    myStackArr.Print();
    cout << "\nTop: " << myStackArr.Top() << ", Bottom: " << myStackArr.Bottom() << "\n";
    myStackArr.Pop();
    myStackArr.Pop(); 
    myStackArr.Pop();
    cout << "\n\nStack Elements after Popping 3 items: "; 
    myStackArr.Print();
    cout << "\nTop: " << myStackArr.Top() << ", Bottom: " << myStackArr.Bottom() << "\n";
    
    cout << "\n\nGet item By index 0: " << myStackArr.GetItem(0) << endl;
    cout << "\n\nReverse the Stack: "; myStackArr.Reverse();
    myStackArr.Print();
    cout << "\n\nUpdate item at index 1 to 100: "; myStackArr.UpdateItemByIndex(1, 100);
    myStackArr.Print();
    cout << "\n\nInsert 5 at front: "; myStackArr.InsertAtFront(5);
    myStackArr.Print();
    cout << "\n\nInsert 70 at back: "; myStackArr.InsertAtBack(70);
    myStackArr.Print();
}

static void TestMyString()
{
    clsMyString myString;
    myString.SetValue("Hello");
    cout << "Current Value: " << myString.GetValue() << endl;
    myString.SetValue("World");
    cout << "Current Value: " << myString.GetValue() << endl;
    myString.SetValue("!");
    cout << "Current Value: " << myString.GetValue() << endl;
    myString.PrintHistory();
    myString.Undo();
    cout << "Current Value: " << myString.GetValue() << endl;
    myString.Undo();
    cout << "Current Value: " << myString.GetValue() << endl;
    myString.Undo();
    cout << "Current Value: " << myString.GetValue() << endl;
    myString.Redo();
    cout << "Current Value: " << myString.GetValue() << endl;
    myString.Redo();
    cout << "Current Value: " << myString.GetValue() << endl;
    myString.Redo();
    cout << "Current Value: " << myString.GetValue() << endl;
}

static void TestQueueLine()
{
    cout << "\n==================================================\n";
    cout << " Testing clsQueueLine with Edge Cases\n";
    cout << "==================================================\n\n";

    // 1. Initialize Queue with prefix "A" and 5 minutes average serve time
    clsQueueLine queueLine("A", 5);

    // ----------------------------------------------------
    // [Edge Case 1]: Operations on Completely Empty Queue
    // ----------------------------------------------------
    cout << " [Test 1]: Operations on completely EMPTY Queue...\n";

    cout << "-> Queue Info (Empty):\n";
    queueLine.PrintQueueInfo();

    cout << "-> LTR Print (Empty): ";
    queueLine.PrintQLineLTR();
    cout << "\n";

    cout << "-> RTL Print (Empty): ";
    queueLine.PrintQLineRTL();
    cout << "\n";

    cout << "-> All Tickets Print (Empty):\n";
    queueLine.PrintAllTickets();

    cout << "-> WhoIsNext(): " << queueLine.WhoIsNext() << " | (Expected: No Clients Left.)\n";
    cout << "-> ServeNextClient(): " << (queueLine.ServeNextClient() ? "Success" : "Failed (Correct Behavior)") << "\n";
    cout << "-> WaitingClients(): " << queueLine.WaitingClients() << " | (Expected: 0)\n";
    cout << "-> ServedClients(): " << queueLine.ServedClients() << " | (Expected: 0)\n\n";

    // ----------------------------------------------------
    // [Edge Case 2]: Single Client in Queue
    // ----------------------------------------------------
    cout << " [Test 2]: Adding a single client (A1)...\n";
    queueLine.IssueTicket(); // Ticket A1 - Expected wait time: 0 minutes

    cout << "-> WhoIsNext(): " << queueLine.WhoIsNext() << " | (Expected: A1)\n";

    cout << "-> LTR Print (Single Item): ";
    queueLine.PrintQLineLTR();
    cout << "\n";

    cout << "-> RTL Print (Single Item): ";
    queueLine.PrintQLineRTL();
    cout << "\n";

    cout << "-> Single Ticket Details:\n";
    queueLine.PrintAllTickets();

    // ----------------------------------------------------
    // [Case 3]: Multiple Clients & Expected Wait Time
    // ----------------------------------------------------
    cout << "\n [Test 3]: Adding more clients (A2, A3)...\n";
    queueLine.IssueTicket(); // A2 (Expected wait time = 5 mins)
    queueLine.IssueTicket(); // A3 (Expected wait time = 10 mins)

    cout << "-> Full Queue LTR: ";
    queueLine.PrintQLineLTR(); // Expected: A1 -> A2 -> A3
    cout << "\n";

    cout << "-> Full Queue RTL: ";
    queueLine.PrintQLineRTL(); // Expected: A3 <- A2 <- A1
    cout << "\n";

    cout << "-> Queue Summary Info:\n";
    queueLine.PrintQueueInfo();

    cout << "-> All Tickets Details:\n";
    queueLine.PrintAllTickets();

    // ----------------------------------------------------
    // [Case 4]: Interleaved Serving and Adding
    // ----------------------------------------------------
    cout << "\n [Test 4]: Serving first client (A1) then adding new one...\n";
    queueLine.ServeNextClient(); // Serves A1

    cout << "-> WhoIsNext() after serving A1: " << queueLine.WhoIsNext() << " | (Expected: A2)\n";
    cout << "-> Current LTR: ";
    queueLine.PrintQLineLTR(); // Expected: A2 -> A3
    cout << "\n";

    cout << "\n-> Issuing new ticket after serving A1...\n";
    queueLine.IssueTicket(); // Must be A4 (not reusing old numbers)

    cout << "-> LTR after addition: ";
    queueLine.PrintQLineLTR(); // Expected: A2 -> A3 -> A4
    cout << "\n";

    // ----------------------------------------------------
    // [Edge Case 5]: Fully Emptying Queue then Re-adding
    // ----------------------------------------------------
    cout << "\n [Test 5]: Completely emptying the queue...\n";
    while (queueLine.WaitingClients() > 0)
    {
        cout << "   [Serving]: " << queueLine.WhoIsNext() << endl;
        queueLine.ServeNextClient();
    }

    cout << "-> ServeNextClient() on empty queue: "
        << (queueLine.ServeNextClient() ? "Success" : "Failed (Correct Behavior)") << endl;

    cout << "-> Queue Info after full drain:\n";
    queueLine.PrintQueueInfo();

    cout << "\n-> Adding new client (A5) to verify counter persistence...\n";
    queueLine.IssueTicket(); // Ticket number must be A5
    cout << "-> WhoIsNext(): " << queueLine.WhoIsNext() << " | (Expected: A5)\n";
    cout << "-> Final LTR: ";
    queueLine.PrintQLineLTR();
    cout << "\n";

    cout << "\n==================================================\n";
    cout << " All tests executed cleanly with zero crashes!\n";
    cout << "==================================================\n";
}

int main()
{
    TestQueueLine();


    return 0;
}

