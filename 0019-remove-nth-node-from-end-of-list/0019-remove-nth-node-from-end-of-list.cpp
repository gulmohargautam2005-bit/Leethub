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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* temp = head;
        int count = 1;
        while(curr->next!=nullptr)
        {
           curr= curr ->next;
           count = count+1;
        }
        if(count==1)
        {
            return nullptr;
        }
        if(count==n)
        {
            return head =head->next;
        }

        int t = count-n;
        int i=1;
        while(i<t)
        {
           temp = temp->next;
           i++;
        }
        if(temp->next!=nullptr)
        {
        ListNode* skip=temp->next->next;
        temp->next = skip;
        }
        else
        {
            temp->next = nullptr;
        }
        return head;

    }
};