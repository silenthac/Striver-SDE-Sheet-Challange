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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>pq;
        pq.push(root);
        bool zigzag=true;
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        while(!pq.empty())
        {
            int s = pq.size();
            vector<int>vec;
            for(int i=0;i<s;i++)
            {
                auto node = pq.front();
                vec.push_back(node->val);
                pq.pop();
                
                if(node->left)
                {
                    pq.push(node->left);
                }
                if(node->right)
                {
                    pq.push(node->right);
                }
                
                
                
            }
            if(zigzag)
            {
                
                    zigzag = false;
            }
            else
            {   reverse(vec.begin(),vec.end());
                zigzag =true;

            }
            ans.push_back(vec);
            
            
        }
        return ans;
        
        
    }
};