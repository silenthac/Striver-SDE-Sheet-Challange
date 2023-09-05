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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
      Node* temp =head;
        Node* newNode = new Node(-1);
        Node* res = newNode;
        
        while(temp!=NULL)
        {
            Node* tempnode = new Node(temp->val);
            mp[temp]=  tempnode;
            newNode->next = tempnode;
            newNode = newNode->next;
            temp =temp->next;
            
        }
        
        temp = head;
        newNode=res->next;
        while(temp!=NULL)
        {
            newNode->random = mp[temp->random];
            newNode = newNode->next;
            temp =temp->next;
            
            
            
        }
        
        return res->next;
        
        
    }
};