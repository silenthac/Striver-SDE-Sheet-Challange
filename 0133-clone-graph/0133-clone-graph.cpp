/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*>mp;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        
        if(mp.find(node)!=mp.end())
            return mp[node];
        
        Node* temp = new Node(node->val);
        
        
        mp[node] =temp;
        
        
        for(auto it:node->neighbors)
        {
            Node* temp1 = cloneGraph(it);
            mp[node]->neighbors.push_back(temp1);
            
        }
        return mp[node];
        
    }
};