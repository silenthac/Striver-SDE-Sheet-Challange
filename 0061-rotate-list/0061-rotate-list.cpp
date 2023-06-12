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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return 0;
        
        if(k==0)
            return head;
        ListNode* temp =head;
        ListNode* temp2 =head;
        int count=1;
        while(temp2->next!=NULL)
        {
            count++;
            temp2 =temp2->next;
        }
        cout<<count;
        
        k = k%count;
        if(k==0)
            return head;
        while(k)
        {
            temp =temp->next;
            k--;
        }
        
        ListNode* slow = head;
        while(temp->next!=NULL)
        {
            slow =slow->next;
            temp =temp->next;
        }
        
        ListNode* res = slow->next;
        temp->next = head;
        slow->next = NULL;
        return res;
        
        
    }
};