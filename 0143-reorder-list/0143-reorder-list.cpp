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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        ListNode* curr1 =head;
        int count =0;
        int i=0;
        while(curr!=nullptr)
        {
            count = count +1;
            curr =curr->next;
        }
        curr=head;

        while(i<((count-1)/2))
        {
            int counter = count-2*i-1;
            curr1= curr;
            if(counter==0)
            {
                curr1=curr->next;
                curr->next=nullptr;
                curr1->next =curr;
                break;
            }
            while(curr1->next!=nullptr && counter--)
            {
                curr1=curr1->next;
            }
            ListNode*next =curr->next;
            curr->next=curr1;
            curr1->next =next;
            curr=next;
            i++;
        }
        if(curr != nullptr)
        {
            if(count % 2 == 0)
                curr->next->next = nullptr;
            else
                curr->next = nullptr;
        }
        
    }
};