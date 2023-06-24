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


//clone graph using BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        unordered_map<Node*,Node*>mp;
        queue<Node*>pq;
        pq.push(node);
        Node* res = new Node(node->val);
        mp[node] =res;
        
        while(!pq.empty())
        {
            auto top= pq.front();
            pq.pop();
            
            for(auto it:top->neighbors)
            {
                if(mp.find(it)!=mp.end())
                {
                   mp[top]->neighbors.push_back(mp[it]); 
                }
                else
                {
                    Node* temp =new Node(it->val);
                    mp[it] =temp;
                    mp[top]->neighbors.push_back(temp);
                    pq.push(it);
                }
            }
        }
        
        return res;
        
        
    }
};