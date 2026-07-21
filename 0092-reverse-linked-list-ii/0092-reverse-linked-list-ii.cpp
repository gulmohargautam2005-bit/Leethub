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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr =head;
        ListNode* start=head;
        ListNode* prev = nullptr;
        ListNode* save = nullptr;
        ListNode* first = head;
        int counter2  = right-left+1;
        int counter1= left-1;
        if(left ==right)
            return head;
        while( start!=nullptr && counter1-- )
        {
            save = start;
            start=start->next;
            first=start;
        }
        while(start!=nullptr && counter2--)
        {
        
        ListNode* next = start->next;
        start->next=prev;
        prev =start;
        start = next;
        }
        if(save)
        {
            save->next = prev;  
        }
        else
        {
            head=prev;
        }
        first->next=start;
  
        return head;
    }
};