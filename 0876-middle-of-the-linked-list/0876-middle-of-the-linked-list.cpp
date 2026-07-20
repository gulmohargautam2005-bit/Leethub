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
    ListNode* middleNode(ListNode* head) {
        int count =1;
        int mid =0;
        ListNode* curr =head;
        while(curr->next!=nullptr)
        {
            count = count+1;
            curr = curr->next;
        }
        if(count%2==0)
        {
            mid = (count/2)+1;
        }
        else
        {
            mid = (count+1)/2;
        }
        ListNode* temp=head;

        int i =1;
        while(i<mid)
        {
             temp = temp->next;
             i++;
        }
        return temp;

        
    }
};
