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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0);
        ListNode dummy2(0);
        ListNode* tail1=&dummy1;
        ListNode* tail2=&dummy2;
        ListNode*curr =head;
        while(curr!=nullptr)
        {
            if(curr->val<x)
            {
                tail1->next=curr;
                tail1=tail1->next;
            }
            else
            {
                tail2->next = curr;
                tail2=tail2->next;
            }
            curr= curr->next;
        }
         tail2->next = nullptr; 
        if(dummy1.next==nullptr)
            return dummy2.next;
        if(dummy2.next==nullptr)
            return dummy1.next;


        tail1->next=dummy2.next;
        return dummy1.next;
    }

};