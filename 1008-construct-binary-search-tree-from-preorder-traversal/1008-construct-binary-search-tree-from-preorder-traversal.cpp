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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder;
        unordered_map<int,int>mp;
        for(auto i:preorder)
        {
            inorder.push_back(i);
        }
        
        sort(inorder.begin(),inorder.end());
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] =i;
        }
        
        int pstart = 0;
        int pend = preorder.size()-1;
        int instart =0;
        int inend =inorder.size()-1;
        return solve(inorder,instart,inend,preorder,pstart,pend,mp);
        
        
    }
    
    TreeNode* solve(vector<int>&inorder,int instart,int inend,vector<int>&preorder,int pstart,int pend,unordered_map<int,int>&mp)
    {
        if(instart>inend||pstart>pend)
            return NULL;
        TreeNode *root = new TreeNode(preorder[pstart]);
        int index = mp[root->val];
        int nele = index-instart;
        root->left = solve(inorder,instart,index-1,preorder,pstart+1,pstart+nele,mp);
        root->right =solve(inorder,index+1,inend,preorder,pstart+nele+1,pend,mp);
        return root;
        
    }
    
};