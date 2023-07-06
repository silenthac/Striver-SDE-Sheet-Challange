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
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        solve(root,res);
        return res;
        
    }
    
    int solve(TreeNode* root,int& res)
    {
        if(root==NULL)
            return 0;
        int left = solve(root->left,res);
        int right =solve(root->right,res);
        int temp=0;
        if(left<0&&right<0)
        {
            temp = root->val;
        }
        else
        {
         temp = root->val+max(left,right);
        }
        int ans = max(temp,root->val+left+right);
        res= max(res,ans);
        return temp;
    }
};