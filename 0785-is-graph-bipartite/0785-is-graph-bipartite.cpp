class Solution {
public:
    //lets do it by dfs
     // if we are able to  divide the graph in  two color then well and good otherwise  graph is   not bipertite
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n =graph.size();
    
        vector<int>adj[n+1];
        
        for(int i=0;i<n;i++)
        {
            for(auto val:graph[i])
            {
            adj[i].push_back(val);
            adj[val].push_back(i);
            }
        }
        
        vector<int>visited(n,false);
        vector<int>color(n);
        
        for(int i=0;i<n;i++)
        {
            bool bipertite =true;
            if(!visited[i])
            {
                solve(i,adj,visited,color,0,bipertite);
                if(bipertite==false)
                    return false;
                
            }
        }
       
        
        return true;
        
        
        
    }
    
    void solve(int node,vector<int>adj[],vector<int>&visited,vector<int>&color,int curr_color,bool&bipertite)
    {
        visited[node]=true;
        color[node] = curr_color;
        
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                solve(it,adj,visited,color,!curr_color,bipertite);
            }
            else if(curr_color==color[it])
            {
                bipertite =false;
                return;
            }
        }
    }
};