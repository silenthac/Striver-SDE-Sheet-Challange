class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        priority_queue<pair<double,int>>pq;
        pq.push({1.00,start});
        vector<double>prob(n,INT_MIN);
        prob[start] = 1.00;
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            
            for(auto it:adj[top.second])
            {
              if(prob[top.second]*it.second>prob[it.first])
              {
                  prob[it.first] = prob[top.second]*it.second;
                  pq.push({prob[it.first],it.first});
              }
            }
        }
        
        
        if(prob[end]==INT_MIN)
        {
            return 0.000;
            
        }
        else
        {
            return prob[end];
        }
                 
                 
        
        
        
    }
};