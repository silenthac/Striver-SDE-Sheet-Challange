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
    int diameterOfBinaryTree(TreeNode* root) {
        int res =0;
        solve(root,res);
        return res-1;
        
        
    }
    
    int solve(TreeNode* root,int& res)
    {
        if(root==NULL)
            return 0 ;
        
        int left = solve(root->left,res);
        int right = solve(root->right,res);
        int ans=0;
        int temp = 1+max(left,right);
         ans = max(temp,1+left+right);
        res = max(res,ans);
        return temp;
    }
};