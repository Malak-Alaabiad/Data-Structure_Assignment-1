#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

// Node class for linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {} // Constructor
};

// Sorted Linked List Class
class SortedLinkedList
{
private:
    Node *head; // Pointer to the head of the list
    static int Size; // Static variable to store the size of the list
public:
    SortedLinkedList() : head(nullptr) {} // Constructor

    // Insert a value while keeping the list sorted
    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (!head || head->data >= value)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next && current->next->data < value)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        Size++;
    }

    // Delete node at given index
    void remove(int index)
    {
        if (index < 0 || index >= Size)
            throw out_of_range("Index out of range");
        if (!head)
            return;
        Node *temp = head;
        if (index == 0)
        {
            head = head->next;
            delete temp;
            Size--;
            return;
        }
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        if (!temp->next)
            return;
        Node *next = temp->next->next;
        delete temp->next;
        temp->next = next;
        Size--;
    }

    // Overloaded operators
    friend ostream &operator<<(ostream &os, const SortedLinkedList &list)
    {
        Node *current = list.head;
        while (current)
        {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }

    int operator[](int index)
    {
        if (index < 0 || index >= Size)
            throw out_of_range("Index out of range");
        Node *current = head;
        for (int i = 0; current != nullptr && i < index; i++)
        {
            current = current->next;
        }
        if (!current)
            throw out_of_range("Index out of range");
        return current->data;
    }

    ~SortedLinkedList() // Destructor to free memory
    {
        Node *current = head;
        while (current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};

int SortedLinkedList::Size = 0; // Initialize static member

int main()
{
    SortedLinkedList list;
    list.insert(5);
    list.insert(3);
    list.insert(8);
    list.insert(1);
    cout << list << endl; // Output: 1 3 5 8

    list.remove(2);
    cout << list << endl; // Output: 1 3 8

    list.remove(0);
    list.remove(0);
    list.remove(0);
    try
    {
        cout << list[1] << endl; // Output: 3
    }
    catch (const out_of_range &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}