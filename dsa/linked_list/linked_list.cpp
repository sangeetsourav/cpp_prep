/*
List:
    - Stores  elements of a specified data type.
    - Empty list has size 0.
    - Insert elements
    - Remove elements
    - Count elements.
    - Read/write/modify element at a position.

For arrays:
    - Access is O(1).
    - Insertion/deletion at beginning or middle is O(n) as we have to shift the elements.
    - Insertion/deletion at end is O(1) but can be O(n) if we run out of size and need to create a new larger array.
    - We will have to allocate more memory than required because we would need to declare a large array.

For linked lists:
    - Access is O(n).
    - Insertion/deletion at beginning is O(1) as we just need to update the address of the head node.
    - Insertion/deletion at end or middle is O(n) as we need to traverse the list to get to the end
*/

#include<iostream>

struct Node{
    int data;
    Node* next;
}

int main()
{   
    // Pointer to the head node
    Node* A;
    A = NULL;
    
    // Allocate memory for a node
    // temp is not the node, its a pointer to the actual Node location
    Node* temp = new Node;
    
    temp->data = 2;
    temp->next = NULL;
    
    A = temp; // Now A points to the newly created node.
    
}
