class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        if(grid[grid.size()-1][grid[0].size()-1]==1)
        {
            return 0;
        }
        return solve(0,0,grid,dp);
        
        
    }
    
    
    int solve(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(row==grid.size()-1&&col==grid[0].size()-1)
            return 1;
        
       
        
        if(row>=grid.size()||col>=grid[0].size()||grid[row][col]==1)
            return 0;
        
        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        
        int a1 = solve(row+1,col,grid,dp);
        int a2 = solve(row,col+1,grid,dp);
        return  dp[row][col] =a1+a2;
    }
};