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
        ListNode* res =head;
        ListNode* temp =head;
        while(n--)
        {
            temp =temp->next;
        }
        if(temp==NULL)
            return head->next;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            head =head->next;
        }
        
        head->next =head->next->next;
        return res;
        
        
        
    }
};