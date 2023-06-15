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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>pq;
        pq.push(root);
        int permlevel =1;
        long long ans=root->val;
        int level=0;
        while(!pq.empty())
        {
            int s = pq.size();
            int count=0;
            for(int i=0;i<s;i++)
            {
                auto top =pq.front();
                pq.pop();
                count+=top->val;
                if(top->left)
                {
                    pq.push(top->left);
                }
                if(top->right)
                {
                    pq.push(top->right);
                }
            }
            level++;
            if(count>ans)
            {
                ans=count;
                permlevel =level;
            }
        }
        return permlevel;
        
        
    }
};