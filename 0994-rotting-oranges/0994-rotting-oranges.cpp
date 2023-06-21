class Solution {
public:
    vector<pair<int,int>>dir ={{0,-1},{-1,0},{0,+1},{+1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>pq;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    grid[i][j] = 0;
                    pq.push({i,j});
                }
            }
        }
        
    
        
        int count=0;
        
        while(!pq.empty())
        {
            
            int s =pq.size();
            for(int i=0;i<s;i++)
            {
                auto top =pq.front();
                pq.pop();
                int x = top.first;
                int y =top.second;
                
                for(int j=0;j<dir.size();j++)
                {
                    int currx = x+dir[j].first;
                    int curry = y+dir[j].second;
                    
                    if(currx>=0&&currx<grid.size()&&curry>=0&&curry<grid[0].size()&&grid[currx][curry]==1)
                    {
                        pq.push({currx,curry});
                        grid[currx][curry]=0;
                    }
                }
            }
            if(!pq.empty())
            {
                count++;
            }
            
        }
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return count;
        
    }
};