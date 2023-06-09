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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* res = new ListNode();
        ListNode* head =res;
        while(l1!=NULL&&l2!=NULL)
        {
            int sum = l1->val+l2->val+carry;
            carry = sum/10;
            sum =sum%10;
            res->next = new ListNode(sum);
            res =res->next;
            l1 =l1->next;
            l2 =l2->next;
        }
        while(l1!=NULL)
        {
            int sum = l1->val+carry;
            carry = sum/10;
            sum =sum%10;
            res->next = new ListNode(sum);
            res =res->next;
            l1 =l1->next;
        }
        
        while(l2!=NULL)
        {
             int sum = l2->val+carry;
            carry = sum/10;
            sum =sum%10;
            res->next = new ListNode(sum);
            res =res->next;
            l2 =l2->next;
        }
        if(carry!=0)
        {
            res->next= new ListNode(carry);
        }
        return head->next;
        
        
    }
};