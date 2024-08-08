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
};

void insert_at_beginning(Node** pointerToHead, int x)
{
    // Create the node
    Node * temp = new Node;
    temp->data = x;
    temp->next = NULL;
    
    // If list is empty
    if(*pointerToHead == NULL)
    {
        *pointerToHead = temp;
    }
    else
    {
        temp->next = *pointerToHead;
        *pointerToHead = temp;
    }
    
    // Smaller version
    // temp->next = head
    // head = temp;
}

void print_linked_list(Node** pointerToHead)
{
    Node * temp = *pointerToHead;
    
    while(temp != NULL)
    {
        std::cout<<temp->data<<' ';
        temp = temp->next;
    }
    
    std::cout<<"\n";
}

int main()
{   
    // Empty list
    Node* head = NULL;    // Pointer to the head node
    
    std::cout<<"How many numbers?\n";
    int n{};
    std::cin >> n;
    
    int x{};
    for(int i = 0; i < n; i++)
    {
        std::cout<<"Enter the number: \n";
        std::cin >> x;
        insert_at_beginning(&head, x);
        print_linked_list(&head);
    }
    
}
