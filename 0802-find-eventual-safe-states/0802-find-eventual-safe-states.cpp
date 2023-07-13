class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<vector<int>>adj(graph.size());
        vector<int>vec(graph.size(),0);        
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
                 adj[graph[i][j]].push_back(i);
                vec[i]++;
            }
        }
        
        queue<int>pq;
        
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]==0)
            {
                pq.push(i);
            }
        }
        vector<int>ans;
        
        while(!pq.empty())
        {
            auto top =pq.front();
            
            pq.pop();
            ans.push_back(top);
            
            for(auto it: adj[top])
            {
                vec[it]--;
                if(vec[it]==0)
                {
                    pq.push(it);
                }
                
            }
        
        }
     sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};