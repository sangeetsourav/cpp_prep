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

void insert_at(int x, int pos)
{
    // Create the node
    Node* temp = new Node;
    temp->data = x;
    
    // If list is empty
    if(head==NULL)
    {
        head = temp;
        temp->next = NULL;
    }
    else
    {
        if(pos==1)
        {
            Node* next_node = head;
            head = temp;
            temp->next = next_node;
        }
        else
        {
            int index=1;
            
            Node* location = head;
        
            while(index < pos - 1)
            {
                location = location->next;
                ++index;
                if(location->next == NULL)
                {
                    break;
                }
            }
            
            Node* next_node = location->next;
            location->next = temp;
            temp->next = next_node;
        }
    }
}

void delete_at(int pos)
{
    // If list is empty
    if(head==NULL)
    {
        return;
    }
    else
    {
        if(pos==1)
        {
            Node* next_node = head;
            head = head->next;
            // Deallocate deleted node
            delete next_node;
        }
        else
        {
            int index=1;
            
            Node* location = head;
        
            while(index < pos - 1)
            {
                location = location->next;
                ++index;
                if(location->next == NULL)
                {
                    break;
                }
            }
            
            if(location->next != NULL)
            {
                Node* next_node = location->next;
                location->next = location->next->next;
                // Deallocate deleted node
                delete next_node;
            }
        }
    }    
    
}

void print_linked_list()
{
    Node * temp = head;
    
    std::cout<<"List: ";
        
    while(temp != NULL)
    {
        std::cout<<temp->data<<' ';
        temp = temp->next;
    }
    
    std::cout<<"\n";
}

void print_linked_list_recursion(Node * n, bool reverse)
{
    if(n==NULL)
    {
        return; //Exit condition
    }
    if(!reverse)
    {
        std::cout<<n->data<<' ';
    }
    print_linked_list_recursion(n->next, reverse);
    if(reverse)
    {
        std::cout<<n->data<<' ';
    }
}

// Reverse the links
void reverse_iterative()
{
    Node* location = head;
    Node* previous_node = NULL;
    
    while(location->next!=NULL)
    {
        Node* next_node = location->next;
        
        location->next = previous_node;
        
        previous_node = location;
        
        location = next_node;
    }
    
    // For final node
    location->next = previous_node;
    head = location;
}

void reverse_recursion(Node * n)
{
    if(n->next==NULL)
    {
        // So now we are at the last node.
        head = n;
        return;
    }
    
    reverse_recursion(n->next);
    // We go backwards
    n->next->next = n;
    n->next = NULL;
}

int main()
{   
    // Empty list
    head = NULL; 
    
    // Insert
    insert_at(1,1); //1
    print_linked_list();
    insert_at(10,1); //10, 1    
    print_linked_list();
    insert_at(3,2); //10,3,1
    print_linked_list();
    insert_at(4,3); //10,3,4,1
    print_linked_list();
    delete_at(1); //3,4,1
    print_linked_list();
    delete_at(2); //3,1
    print_linked_list();
    delete_at(100); //3,1
    print_linked_list();    
    delete_at(2); //3
    print_linked_list();   
    insert_at(99,2); //3, 99
    print_linked_list();   
    insert_at(78,2); //3, 78, 99
    print_linked_list();   
    insert_at(34,1); //34, 3, 78, 99
    print_linked_list();       
    reverse_iterative(); // 99, 78, 3, 34
    print_linked_list();
    delete_at(1);
    delete_at(1);    
    delete_at(1); // 34 
    reverse_iterative(); // 34
    print_linked_list();
    insert_at(35,2);
    insert_at(36,3);   
    insert_at(37,4);    //34, 35, 36, 37
    print_linked_list_recursion(head,false); //34, 35, 36, 37
    std::cout<<"\n";
    print_linked_list_recursion(head,true); //37, 36, 35, 34
    std::cout<<"\n";
    print_linked_list(); //34, 35, 36, 37
    reverse_recursion(head); //37, 36, 35, 34
    print_linked_list();
}
