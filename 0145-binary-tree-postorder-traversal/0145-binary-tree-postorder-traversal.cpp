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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int>ans;
        stack<TreeNode*>stk;
            stk.push(root);
          TreeNode* top;
        while(!stk.empty())
        {
            top =stk.top();
            if(top->left!=NULL)
            {
                stk.push(top->left);
                top->left=NULL;
            }
            
            else
            {
                if(top->right!=NULL)
                {
                    stk.push(top->right);
                    top->right=NULL;
                }
                else
                {
                    ans.push_back(top->val);
                    stk.pop();
                }
            }
        }
        return ans;
        
        
    }
};