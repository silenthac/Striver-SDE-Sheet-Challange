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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>stk;
        vector<int>ans;
        while(true)
        {
            if(root!=NULL)
            {
                ans.push_back(root->val);
                stk.push(root);
                root =root->left;
                
            }
            
            else
            {
                if(stk.empty())
                {
                    break;
                }
                root =stk.top();
                stk.pop();
                root = root->right;
            }
            
        }
        return ans;
        
    }
};