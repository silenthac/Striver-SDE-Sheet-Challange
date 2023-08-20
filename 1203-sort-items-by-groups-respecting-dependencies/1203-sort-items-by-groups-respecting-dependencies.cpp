class Solution {
public:
    
//     vector<int>topo(vector<vector<int>>&adj,vector<int>&indegree)
//     {
//         queue<int>pq;
//         vector<int>vec;
//         for(int i=0;i<indegree.size();i++)
//         {
//             if(indegree[i]==0)
//             {
               
//                 pq.push(i);
//             }
//         }
//         while(!pq.empty())
//         {
//             auto top =pq.front();
//             pq.pop();
//              vec.push_back(top);
            
//             for(auto it:adj[top])
//             {
//                 indegree[it]--;
//                 if(indegree[it]==0)
//                 {
                   
//                     pq.push(it);
                    
//                 }
//             }
            
//         }
        
//         if(indegree.size()==vec.size())
//         {
//             return vec;
//         }
//         else
//         {
//             return {};
//         }
//     }
    
    
    vector<int> topo( vector<int> adj[], vector<int> &inDegree ){

        vector<int> ans;
        queue<int> q;

        // for each loop will not work
        for(int i = 0; i<inDegree.size() ; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        while( !q.empty() ){
            int node = q.front();
            q.pop();
            ans.push_back( node );

            for( auto &it : adj[node] ){
                inDegree[it]--;
                if( inDegree[it] == 0 ) q.push( it );
            }
        }
        
        if(inDegree.size()!=ans.size())
        {
            return {};
        }

        return ans ;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        // 1st step >>> change the group of -1 and give unique group to all those; 
        int groupId = m;
        for(int i=0;i<group.size();i++)
        {
            if(group[i]==-1)
            {
                group[i]  =groupId;
                groupId++;
            }
        }
        
        // 2nd step >>make group graph and item graph
        vector<int>indegree1(n,0);
        vector<int>indegree2(groupId,0);
        vector<int>adj1[n];
        vector<int>adj2[groupId];
        for(int i=0;i<n;i++)
        {
            for(auto it:beforeItems[i])
            {
                adj1[it].push_back(i);
                indegree1[i]++;
                
                if(group[i]!=group[it])
                {
                    adj2[group[it]].push_back(group[i]);
                    indegree2[group[i]]++;
                }
            }
        }
        
        // vector<int>vec1;
        // vector<int>vec2;
        
       vector<int>vec1 =  topo(adj1,indegree1);
       vector<int>vec2 = topo(adj2,indegree2);
        if(vec1.empty()||vec2.empty())
        {
            return {};
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<vec1.size();i++)
        {
            mp[group[vec1[i]]].push_back(vec1[i]);  
        }
        
    vector<int>ans;
        
        for(int i=0;i<vec2.size();i++)
        {
            for(auto it:mp[vec2[i]])
            {
                ans.push_back(it);
            }
        }
        return ans;
        
        
        
        
        
        
    }
};