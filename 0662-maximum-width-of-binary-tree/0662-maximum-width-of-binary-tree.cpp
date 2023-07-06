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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>pq;
        pq.push({root,0});
        int ans=0;
        while(!pq.empty())
        {
            int s = pq.size();
            int currmin = pq.front().second;
            int rightmost;
            int leftmost;
            for(int i=0;i<s;i++)
            {
               int index = pq.front().second-currmin;
                auto node =pq.front().first;
                pq.pop();
                
               
                if(i==0)
                {
                    leftmost = index;
                }
                
                if(i==s-1)
                {
                    rightmost = index;
                }
                
                if(node->left)
                {
                    pq.push({node->left,1ll*2*index+1});
                }
                if(node->right)
                {
                    pq.push({node->right,2*index+2});
                }
                
                
                
            }
            ans = max(ans,rightmost-leftmost+1);
            
            
        }
        return ans;
        
        
    }
};