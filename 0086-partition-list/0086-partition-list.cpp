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
        ListNode* temp = head;
        ListNode* less = new ListNode(-1);
        ListNode* tempres=less;
        int count=0;
        
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                less->next = new ListNode(temp->val);
                less = less->next;
                
            }
            else if(temp->val==x)
            {
                count++;
            }
            
            temp=temp->next;
            
        }
        
         
        
        // while(count--)
        // {
        //     less->next = new ListNode(x);
        //     less =less->next;
        // }
        
       
        
        temp =head;
        while(temp!=NULL)
        {
            if(temp->val>=x)
            {
                less->next = new ListNode(temp->val);
                less  = less->next;
            }
            
            temp =temp->next;
        }
        
         return tempres->next;
        
       
        
        
        
    }
};