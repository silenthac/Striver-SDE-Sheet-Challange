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
    
    ListNode* reverse(ListNode* head,ListNode* end)
    {
        if(head==end||head->next==end)
        {
            return head;
        }
        
        ListNode* res =  reverse(head->next,end);
         head->next->next = head;
        head->next = end;
        return res;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        
        ListNode* prev;
        ListNode* prevLow=head;
        ListNode* high = head;
        int count=1;
        while(count<left)
        {
            prev = prevLow;
            prevLow = prevLow->next;
            
            count++;
        }
        
        count=1;
        while(count<=right)
        {
            high = high->next;
            count++;
            
        }
        if(left==1)
        {
            return reverse(prevLow,high);
        }
        
        
         prev->next = reverse(prevLow,high);
        return head;
        
        
    }
};