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
    ListNode* getmid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* a ,ListNode* b)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(a!=nullptr && b!=nullptr)
        {
            if(a->val<=b->val)
            {
                tail->next = a;
                a=a->next;
            }
            else
            {
                tail->next=b;
                b=b->next;
            }
            tail = tail->next;
        }
        tail->next = (a!=nullptr)?a:b;
        return dummy.next;

    }
    ListNode* mergesort(ListNode* list)
    {
        if(list==nullptr||list->next==nullptr)
        {
            return list;
        }
        ListNode* mid = getmid(list);
        ListNode* right = mid->next;
        mid->next =nullptr;
        ListNode*left = mergesort(list);
        right =mergesort(right);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        for(int i =0;i<n;i++)
        {
            if(lists[i] == nullptr) continue;
            ListNode* curr = lists[i];
            while(curr->next!=nullptr)
            {
                 curr= curr->next;
            }
            int j =i+1;
            while(j<n && lists[j]==nullptr)
            {
              j++;
            }
            if(j<n)
            {
                curr->next=lists[j];
            }
            
        }
        ListNode* head = nullptr;
        for(int i = 0; i < n; i++) {
            if(lists[i] != nullptr) { head = lists[i]; break; }
        }
        return mergesort(head);
        
    }
};