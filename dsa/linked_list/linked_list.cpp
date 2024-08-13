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

Node* head;    // Global, Pointer to the head node

void insert_at_beginning(int x)
{
    // Create the node
    Node * temp = new Node;
    temp->data = x;
    temp->next = NULL;
    
    // If list is empty
    if(head==NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    
    // Smaller version
    // temp->next = head
    // head = temp;
}

void print_linked_list()
{
    Node * temp = head;
    
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
    head = NULL; 
    
    std::cout<<"How many numbers?\n";
    int n{};
    std::cin >> n;
    
    int x{};
    for(int i = 0; i < n; i++)
    {
        std::cout<<"Enter the number: \n";
        std::cin >> x;
        insert_at_beginning(x);
        print_linked_list();
    }
    
}
