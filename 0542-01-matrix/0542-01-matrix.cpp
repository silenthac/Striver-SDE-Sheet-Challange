class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int,int>>vec = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>>dist(mat.size(),vector<int>(mat[0].size(),-1));
        queue<pair<int,int>>pq;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
              
                  if(mat[i][j]==0)
                  {
                      dist[i][j]=0;
                      pq.push({i,j});
                  }
                
            }
                
        }
        while(!pq.empty())
        {
            auto top = pq.front();
            pq.pop();
            int parow = top.first;
            int pacol = top.second;
            
            
            for(int i=0;i<4;i++)
            {
                int currow = parow+vec[i].first;
                int currcol = pacol+vec[i].second;
                if(currow<0||currow>=mat.size()||currcol<0||currcol>=mat[0].size()||dist[currow][currcol]!=-1)
                    continue;
                dist[currow][currcol] = dist[parow][pacol]+1;
                pq.push({currow,currcol});
            }
        }
        return dist;
        
        
    }
    
    

};