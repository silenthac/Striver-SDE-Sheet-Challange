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
    
    ListNode* reverse(ListNode* head)
    {
        if(head->next==NULL)
            return head;
        
        
        
        
        ListNode* temp = reverse(head->next);
        head->next->next =head;
        head->next =NULL;
        return temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>stk1;
        stack<int>stk2;
        while(l1!=NULL)
        {
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            stk2.push(l2->val);
            l2 =l2->next;
        }
        
        int carry=0;
        ListNode*head = new ListNode(0);
        ListNode*realhead =head;
        while(!stk1.empty()&&!stk2.empty())
        {
            int res = stk1.top()+stk2.top()+carry;
            stk1.pop();
            stk2.pop();
            carry = res/10;
            res = res%10;
            head->next =  new ListNode(res);
            head =head->next;
            
        }
        while(!stk1.empty())
        {
            int res = stk1.top()+carry;
            stk1.pop();
            
            carry = res/10;
            res = res%10;
           head->next  =  new ListNode(res);
            head =head->next;
            
        }
        
        while(!stk2.empty())
        {
            int res = stk2.top()+carry;
            stk2.pop();
            
            carry = res/10;
            res = res%10;
            head->next =  new ListNode(res);
            head =head->next;
            
        }
        if(carry)
        {
          head->next =  new ListNode(carry);
            head =head->next;  
        }
        
        
        return reverse(realhead->next);
        
    }
};