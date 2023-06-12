/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* tempheadA = headA;
        ListNode* tempheadB = headB;
        while(tempheadA!=tempheadB)
        {
//             if(tempheadA==NULL&&tempheadB==NULL)
//                 return NULL;
            
//            else if(tempheadA==tempheadB)
//             {
//                 return tempheadA;
//             }
//             else if(tempheadA==NULL)
//             {
//                 tempheadA = headB;
//             }
            
//             else if(tempheadB==NULL)
//             {
//                 tempheadB = headA;
//             }
            tempheadA = tempheadA->next;
            tempheadB = tempheadB->next;
            if(tempheadA==NULL&&tempheadB==NULL)
                return NULL;
            
           
            else if(tempheadA==NULL)
            {
                tempheadA = headB;
            }
            
            else if(tempheadB==NULL)
            {
                tempheadB = headA;
            }
        }
        return tempheadA;
        
        
    }
};