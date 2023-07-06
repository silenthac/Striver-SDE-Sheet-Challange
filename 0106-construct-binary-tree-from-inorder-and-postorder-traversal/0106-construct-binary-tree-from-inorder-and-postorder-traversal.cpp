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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n =inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]= i;
            
        }
        int postOrderIndex =n-1;
        
        return solve(inorder,postorder,mp,0,inorder.size()-1,postOrderIndex);
        
    }
    
    TreeNode* solve(vector<int>&inorder,vector<int>&postorder,unordered_map<int,int>&mp,int left,int right,int &postOrderIndex)
    {
        if(left>right)
            return NULL;
        TreeNode* temp_Node = new TreeNode(postorder[postOrderIndex--]);
        int index = mp[temp_Node->val];
        
        temp_Node->right = solve(inorder,postorder,mp,index+1,right,postOrderIndex);
        temp_Node->left = solve(inorder,postorder,mp,left,index-1,postOrderIndex);
        
        return temp_Node;
    }
};