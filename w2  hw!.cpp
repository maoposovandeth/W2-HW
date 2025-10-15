#include <iostream>
using namespace std;
// Define a node of the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// 1 Insert at the Front
void insertFront(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the front.\n";
}

// 2️ Insert at the End
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted " << value << " at the end.\n";
}

// 3️ Insert in the Middle (after a given value)
void insertAfter(Node* head, int afterVal, int value) {
    Node* temp = head;
    while (temp && temp->data != afterVal)
        temp = temp->next;

    if (!temp) {
        cout << "Value " << afterVal << " not found.\n";
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << value << " after " << afterVal << ".\n";
}

// 4️ Delete from the Front
void deleteFront(Node*& head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted " << temp->data << " from front.\n";
    delete temp;
}

// 5️ Delete from the End
void deleteEnd(Node*& head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (!head->next) {
        cout << "Deleted " << head->data << " from end.\n";
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next)
        temp = temp->next;
    cout << "Deleted " << temp->next->data << " from end.\n";
    delete temp->next;
    temp->next = nullptr;
}

// 6️ Delete from the Middle (after a given value)
void deleteAfter(Node* head, int afterVal) {
    Node* temp = head;
    while (temp && temp->data != afterVal)
        temp = temp->next;

    if (!temp || !temp->next) {
        cout << "No node to delete after " << afterVal << ".\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    cout << "Deleted " << delNode->data << " after " << afterVal << ".\n";
    delete delNode;
}

// 7️ Traverse (print list)
void printList(Node* head) {
    cout << "Current List: ";
    if (!head) {
        cout << "Empty\n";
        return;
    }
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// 8️ Swap Two Nodes (by values)
void swapNodes(Node*& head, int x, int y) {
    if (x == y) return;

    Node *prevX = nullptr, *currX = head;
    Node *prevY = nullptr, *currY = head;

    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (!currX || !currY) {
        cout << "One or both values not found.\n";
        return;
    }

    if (prevX)
        prevX->next = currY;
    else
        head = currY;

    if (prevY)
        prevY->next = currX;
    else
        head = currX;

    Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    cout << "Swapped " << x << " and " << y << ".\n";
}

// 9️ Search
void search(Node* head, int key) {
    int pos = 1;
    while (head) {
        if (head->data == key) {
            cout << key << " found at position " << pos << ".\n";
            return;
        }
        head = head->next;
        pos++;
    }
    cout << key << " not found in list.\n";
}
// 10 Compare Linked List vs Array (concept only)
void compareLists() {
    cout << "\nComparison: Linked List vs Array\n";
    cout << "---------------------------------\n";
    cout << "Insert at Front:   LL=O(1), Array=O(n)\n";
    cout << "Insert at End:     LL=O(n), Array=O(1)*\n";
    cout << "Delete at Front:   LL=O(1), Array=O(n)\n";
    cout << "Delete at End:     LL=O(n), Array=O(1)*\n";
    cout << "Access element:    LL=O(n), Array=O(1)\n";
    cout << "Search element:    Both O(n)\n";
    cout << "---------------------------------\n";
}
int main() {
    Node* head = nullptr;

    cout << "--- LINKED LIST CHALLENGES ---\n";

    // Challenge 1 & 2: Insert
    insertFront(head, 10);
    insertFront(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    printList(head);

    // Challenge 3: Insert in middle
    insertAfter(head, 20, 25);
    printList(head);

    // Challenge 4: Delete front
    deleteFront(head);
    printList(head);

    // Challenge 5: Delete end
    deleteEnd(head);
    printList(head);

    // Challenge 6: Delete middle
    deleteAfter(head, 25);
    printList(head);

    // Challenge 7: Traverse already shown by printList
    printList(head);

    // Challenge 8: Swap nodes
    swapNodes(head, 25, 30);
    printList(head);

    // Challenge 9: Search
    search(head, 25);
    search(head, 100);

    // Challenge 10: Compare with Array
    compareLists();
    return 0;
}