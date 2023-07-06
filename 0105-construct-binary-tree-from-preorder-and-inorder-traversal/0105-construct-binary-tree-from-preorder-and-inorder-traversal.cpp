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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        int preIndex=0;
        
        return solve(preorder,inorder,0,n-1,preIndex,mp);
        
        
        
    }
    
    TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int left,int right,int& preIndex,unordered_map<int,int>&mp)
    {
        if(left>right)
            return NULL;
        
        TreeNode * temp_node = new TreeNode(preorder[preIndex++]);
        int index = mp[temp_node->val];
        temp_node->left = solve(preorder,inorder,left,index-1,preIndex,mp);
        temp_node->right = solve(preorder,inorder,index+1,right,preIndex,mp);
        return temp_node;
        
    }
};