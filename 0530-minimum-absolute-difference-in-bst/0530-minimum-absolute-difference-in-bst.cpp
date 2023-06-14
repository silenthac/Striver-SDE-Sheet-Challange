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
    int getMinimumDifference(TreeNode* root) {
        int ans =INT_MAX;
        int prev_val = INT_MAX;
       solve(root,ans,prev_val);
        return ans;
        
    }
    
    
    void solve(TreeNode*root,int &ans,int &prev_val)
    {
        if(root==NULL)
            return;
        
        
        
         solve(root->left,ans,prev_val);
        ans = min(ans,abs(prev_val-root->val));
        prev_val = root->val;
        
       solve(root->right,ans,prev_val);
       
        
       
    }
};