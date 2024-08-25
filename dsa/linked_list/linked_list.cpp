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
    
}
