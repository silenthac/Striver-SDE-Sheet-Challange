class Solution {
public:
    vector<vector<int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int shortestPathAllKeys(vector<string>& grid) {
        int x=-1;
        int y=-1;
        int maxlen=-1;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='@')
                {
                    x = i;
                    y=j;
                    
                }
                
                if(grid[i][j]>='a'&&grid[i][j]<='f')
                {
                    maxlen = max(grid[i][j]-'a'+1,maxlen);
                }
            }
        }
        cout<<maxlen;
        
        vector<int>start = {0,x,y};
        unordered_set<string>visited;
        visited.insert({to_string(0)+" "+to_string(x)+" "+to_string(y)});
        queue<vector<int>>pq;
        pq.push(start);
        int count=0;
        while(!pq.empty())
        {
            int s = pq.size();
            
            for(int i=0;i<s;i++)
            {
                auto top = pq.front();
                pq.pop();
                if(top[0]==(1<<maxlen)-1)
                {
                    return count;
                }
                
                for(auto  it:dirs)
                {
                    int i = top[1]+it[0];
                    int j = top[2]+it[1];
                    int key= top[0];
                    
                    if(i<0||i>=grid.size()||j<0||j>=grid[0].size())
                        continue;
                    if(grid[i][j]=='#')
                    {
                        continue;
                    }
                    
                    if(grid[i][j]>='a'&&grid[i][j]<='f')
                    {
                        key = key|(1<<(grid[i][j]-'a'));
                    }
                    
                    
                    if(grid[i][j]>='A'&&grid[i][j]<='F'&&((key>>(grid[i][j]-'A'))&1)==0)
                    {
                        continue;
                    }
                    
                    if(!visited.count(to_string(key)+" "+to_string(i)+" "+to_string(j)))
                    {
                        visited.insert(to_string(key)+" "+to_string(i)+" "+to_string(j));
                        pq.push({key,i,j});
                    }
                    
                }
                
                
            }
            
            count++;
            
        }
        
        return -1;
        
    }
};