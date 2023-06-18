class Solution {
public:
    int mod = 1e9+7;
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans=0;
        
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                ans= (ans+solve(i,j,grid,dp,-1))%mod;
                
            }
        }
        return ans;
        
         
        
        
    }
    
    int solve(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp,int prev)
    {
        
        if(row>=grid.size()||row<0||col>=grid[0].size()||col<0||prev>=grid[row][col]||grid[row][col]==-2)
            return 0;
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
       
        
        
        
        
         dp[row][col] = (((solve(row+1,col,grid,dp,grid[row][col]))%mod+(solve(row,col+1,grid,dp,grid[row][col]))%mod+(solve(row-1,col,grid,dp,grid[row][col]))%mod+(solve(row,col-1,grid,dp,grid[row][col])))%mod+1)%mod;
        
        
        return dp[row][col];
        
        
        
        
        
        
        
        
       
        
       
        
        
    }
    
};