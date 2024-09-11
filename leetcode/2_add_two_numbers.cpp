/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;

        ListNode* head = nullptr;

        ListNode* current = nullptr;

        int carry_over = 0;

        while(ptr1!=nullptr || ptr2!=nullptr)
        {
            if(current==nullptr)
            {
                current = new ListNode;
                head = current;
            }
            else
            {
                current->next = new ListNode;
                current = current->next;
            }

            int val1{0};
            int val2{0};

            if(ptr1!=nullptr)
            {
                val1 = ptr1->val;
            }

            if(ptr2!=nullptr)
            {
                val2 = ptr2->val;
            }

            int digit = carry_over + val1 + val2;
            
            if(digit>=10)
            {
                digit = digit%10;
                carry_over = 1;
            }
            else
            {
                carry_over = 0;
            }

            current->val = digit;

            if(ptr1!=nullptr)
            {
                ptr1 = ptr1->next;
            }

            if(ptr2!=nullptr)
            {
                ptr2 = ptr2->next;
            }
        }

        if(carry_over!=0)
        {
            current->next = new ListNode(carry_over);
        }

        return head;
    }
};