/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>mp;
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>pq;
        pq.push({root,{0,0}});
        while(!pq.empty())
        {
            auto top =pq.front();
            pq.pop();
            auto node = top.first;
            auto vertical = top.second.first;
            auto level = top.second.second;
            mp[vertical][level].push_back(node->val);
            if(node->left)
            {
                pq.push({node->left,{vertical-1,level+1}});
            }
            if(node->right)
            {
                pq.push({node->right,{vertical+1,level+1}});
            }
        }
        for(auto i:mp)
        {
            vector<int>vec;
            for(auto j:i.second)
            {
                sort(j.second.begin(),j.second.end());
                for(auto k:j.second)
                {
                    vec.push_back(k);
                }
                 
            }
            
            ans.push_back(vec);
        }
        return ans;
        
    }
};