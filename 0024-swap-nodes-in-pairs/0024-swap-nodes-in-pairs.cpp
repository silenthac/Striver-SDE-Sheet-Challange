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
    
     ListNode* reverse(ListNode* start,ListNode* end)
    {
        ListNode* current = start;
       ListNode* prev =NULL;
        ListNode* nxt =NULL;
            while(current!=end)
            {
                nxt =current->next;
                current->next =prev;
                prev =current;
                current =nxt;
                
                
            }
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
         ListNode* ptr =head;
        
        for(int i=0;i<2;i++)
        {
            if(ptr==NULL)
                return head;
            ptr =ptr->next;
        }
        
      ListNode* temp =   reverse(head,ptr);
      head->next =  swapPairs(ptr);
        return temp;
    }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
};