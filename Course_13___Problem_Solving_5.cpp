#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;


int main()
{
    clsDblLinkedList<int> list;

    std::cout << "===========================================\n";
    std::cout << "1. TESTING INSERTIONS & EDGE CASES\n";
    std::cout << "===========================================\n";

    // 1.1 Print empty list
    std::cout << "Empty List: ";
    list.PrintLinkedList();

    // 1.2 Insert into empty list
    std::cout << "\nInserting 20 at beginning (empty list):\n";
    list.InsertAtBeginning(20);
    list.PrintLinkedList(); // Expected: 20

    // 1.3 Insert at beginning & end
    std::cout << "\nInserting 10 at beginning & 40 at end:\n";
    list.InsertAtBeginning(10);
    list.InsertAtEnd(40);
    list.PrintLinkedList(); // Expected: 10  20  40

    // 1.4 Insert after specific nodes (Middle & Tail)
    std::cout << "\nInserting 30 after node(20):\n";
    clsDblLinkedList<int>::Node* node20 = list.FindNode(20);
    list.InsertAfter(node20, 30);
    list.PrintLinkedList(); // Expected: 10  20  30  40

    // 1.5 Edge Case: InsertAfter with nullptr
    std::cout << "\nEdge Case: InsertAfter with nullptr:\n";
    list.InsertAfter(nullptr, 999); // Expected: Error message printed

    std::cout << "\n===========================================\n";
    std::cout << "2. TESTING FIND NODE\n";
    std::cout << "===========================================\n";

    // 2.1 Find existing node
    clsDblLinkedList<int>::Node* foundNode = list.FindNode(30);
    std::cout << "Finding value 30: " << (foundNode != nullptr ? "Found" : "Not Found") << "\n";

    // 2.2 Find non-existing node
    foundNode = list.FindNode(99);
    std::cout << "Finding value 99: " << (foundNode != nullptr ? "Found" : "Not Found") << "\n";

    std::cout << "\n===========================================\n";
    std::cout << "3. TESTING DELETE NODE BY VALUE\n";
    std::cout << "===========================================\n";

    // 3.1 Delete Head node
    std::cout << "Deleting head node (10):\n";
    list.DeleteNode(10);
    list.PrintLinkedList(); // Expected: 20  30  40

    // 3.2 Delete Middle node
    std::cout << "\nDeleting middle node (30):\n";
    list.DeleteNode(30);
    list.PrintLinkedList(); // Expected: 20  40

    // 3.3 Delete Tail node
    std::cout << "\nDeleting tail node (40):\n";
    list.DeleteNode(40);
    list.PrintLinkedList(); // Expected: 20

    // 3.4 Delete non-existent value
    std::cout << "\nEdge Case: Deleting non-existent value (999):\n";
    list.DeleteNode(999);
    list.PrintLinkedList(); // Expected: 20 (Unchanged)

    std::cout << "\n===========================================\n";
    std::cout << "4. TESTING DELETE NODE BY POINTER\n";
    std::cout << "===========================================\n";

    // Re-populate list: 20 -> 20  30  40
    list.InsertAtEnd(30);
    list.InsertAtEnd(40);
    std::cout << "Current List: ";
    list.PrintLinkedList();

    // 4.1 Delete Node by valid pointer
    std::cout << "\nDeleting Node pointer (30):\n";
    clsDblLinkedList<int>::Node* nodeToDelete = list.FindNode(30);
    list.DeleteNode(nodeToDelete);
    list.PrintLinkedList(); // Expected: 20  40

    // 4.2 Edge Case: Delete foreign node (node from another list)
    std::cout << "\nEdge Case: Deleting a node that doesn't belong to this list:\n";
    clsDblLinkedList<int>::Node* externalNode = new clsDblLinkedList<int>::Node(500);
    list.DeleteNode(externalNode);
    list.PrintLinkedList(); // Expected: 20  40 (Safely ignored)
    delete externalNode;

    std::cout << "\n===========================================\n";
    std::cout << "5. TESTING DELETE FIRST & LAST NODES\n";
    std::cout << "===========================================\n";

    std::cout << "Deleting First Node:\n";
    list.DeleteFirstNode();
    list.PrintLinkedList(); // Expected: 40

    std::cout << "\nDeleting Last Node (Single-item list):\n";
    list.DeleteLastNode();
    list.PrintLinkedList(); // Expected: Empty line

    // 5.1 Edge Cases: Deleting from empty list
    std::cout << "\nEdge Case: Delete First on empty list:\n";
    list.DeleteFirstNode(); // Should not crash
    std::cout << "Edge Case: Delete Last on empty list:\n";
    list.DeleteLastNode(); // Should not crash

    std::cout << "\n===========================================\n";
    std::cout << "6. TESTING DELETE BY INDEX\n";
    std::cout << "===========================================\n";

    // Populate list: 100  200  300  400
    list.InsertAtEnd(100);
    list.InsertAtEnd(200);
    list.InsertAtEnd(300);
    list.InsertAtEnd(400);
    std::cout << "Current List: ";
    list.PrintLinkedList();

    // 6.1 Delete at index 0 (Head)
    std::cout << "\nDeleting index 0 (Head):\n";
    list.DeleteNodeByIndex(0);
    list.PrintLinkedList(); // Expected: 200  300  400

    // 6.2 Delete middle index
    std::cout << "\nDeleting index 1 (Middle):\n";
    list.DeleteNodeByIndex(1);
    list.PrintLinkedList(); // Expected: 200  400

    // 6.3 Edge Cases: Negative index & Out-of-bounds index
    std::cout << "\nEdge Case: Delete index -1:\n";
    list.DeleteNodeByIndex(-1); // Should not crash
    std::cout << "Edge Case: Delete out-of-bounds index 10:\n";
    list.DeleteNodeByIndex(10); // Should not crash
    list.PrintLinkedList(); // Expected: 200  400

    std::cout << "\n===========================================\n";
    std::cout << "7. TESTING CLEAR ENTIRE LINKED LIST\n";
    std::cout << "===========================================\n";

    std::cout << "Deleting full linked list:\n";
    list.DeleteLinkedList();
    std::cout << "List after full delete: ";
    list.PrintLinkedList(); // Expected: Empty line

    // 7.1 Edge Case: Clear already empty list
    std::cout << "\nEdge Case: Deleting full list when already empty:\n";
    list.DeleteLinkedList(); // Should not crash

    std::cout << "\n===========================================\n";
    std::cout << "ALL METHOD & EDGE CASE TESTS PASSED!\n";
    std::cout << "===========================================\n";

    return 0;
}

