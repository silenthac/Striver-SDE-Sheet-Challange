/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0)
        {
            return {target->val};
        }
        queue<TreeNode*>pq;
        pq.push(root);
        // vector<vector<int>>vec;
        unordered_map<int,vector<int>>vec;
        while(!pq.empty())
        {
            int s = pq.size();
            for(int i=0;i<s;i++)
            {
                auto top =pq.front();
                pq.pop();
                
                if(top->left!=NULL)
                {
                    vec[top->val].push_back(top->left->val);
                    vec[top->left->val].push_back(top->val);
                    
                    pq.push(top->left);
                    
                }
                
                if(top->right!=NULL)
                {
                    vec[top->val].push_back(top->right->val);
                    vec[top->right->val].push_back(top->val);
                    pq.push(top->right);
                }
                
            }
        }
        
//        for ( const auto &p : vec )
// {
//     cout << p.first << " :";
//     for ( const auto &s : p.second )
//     {
//         cout << ' ' << s;
//     }
//     cout << endl;
        
// }
        int n =vec.size();
        vector<bool>visited(n+1,false);
        vector<int>ans;
        bfs(target->val,vec,visited,ans,k,0);
       // dfs(target->val,vec,visited,ans,k,0);
        
        return ans;
        
    }
    
    void dfs(int index,unordered_map<int,vector<int>>&mp,vector<bool>&visited,vector<int>&ans,int k,int tempk ) {
        //base case
        if(tempk == k) {
            ans.push_back(index);
            return;
        }

        visited[index] = true;
        for(int neighbour : mp[index]) {
            if(!visited[neighbour]) {
                dfs(neighbour,mp,visited,ans,k,tempk+1);
            }
        }
    }
    
    
    void bfs(int index,unordered_map<int,vector<int>>&mp,vector<bool>&visited,vector<int>&ans,int k,int tempk)
    {
        queue<int>q;

          q.push(index);
        
        //bfs
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                
                int curr = q.front();
                q.pop();
                visited[curr]=true;   
                for(int x : mp[curr])
                    if(!visited[x])
                        q.push(x);
            }
            k--;
            //we reached the Kth layer, push the layer in res vector and break bfs
            if(k==0){
                while(!q.empty()){
                    ans.push_back(q.front());
                    q.pop();
                }
                break;
            }
                
        }
        return;
    }
    
    
    
    
};