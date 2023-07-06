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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>stk;
        vector<int>ans;
        TreeNode* curr =root;
        while(true)
        {
            if(curr!=NULL)
            {
                stk.push(curr);
                curr =curr->left;
                
            }
            
            else
            {
                if(stk.empty())
                {
                    break;
                }
                 curr =stk.top();
                stk.pop();
                ans.push_back(curr->val);
                curr =curr->right;    
            }
        }
        return ans;
        
    }
};