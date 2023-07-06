/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node*>pq;
        pq.push(root);
        while(!pq.empty())
        {
            int s=pq.size();
            for(int i=0;i<s;i++)
            {
            auto top=pq.front();
            pq.pop();
            if(pq.empty())
            {
                top->next=NULL;
            }
                if(i==s-1)
                {
                    top->next = NULL;
                }
                else
                {
                    top->next =pq.front();
                }
                
            if(top->left)
            {
                pq.push(top->left);
            }
            if(top->right)
            {
                pq.push(top->right);
            }
            }
        }
        return root;
        
        
    }
};