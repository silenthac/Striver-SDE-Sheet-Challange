/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//make a map of value and its address

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        
        Node* temp =head;
        Node* res = new Node(-1);
        Node*head2=res;
        
        
        while(temp!=NULL)
        {
            
                res->next = new  Node(temp->val);
            mp[temp] =res->next;
                res =res->next;
                temp =temp->next;
            
        }
        temp =head;
        head2 =head2->next;
        Node* ans=head2;
        while(temp!=NULL)
        {
            if(temp->random==NULL)
            {
                head2->random =NULL;
            }
            else
            {
                 head2->random=mp[temp->random];
            }
            
            
            head2 =head2->next;
            temp =temp->next;
        }
        return ans;
        
        
        
        
        
    }
};