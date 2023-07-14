class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        
        return solve(0,0,grid,dp);
        
        
    }
    
    int solve(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(row==grid.size()-1&&col==grid[0].size()-1)
        {
            return grid[row][col];
        }
        
        if(row<0||row>=grid.size()||col<0||col>=grid[0].size()||grid[row][col]==-1)
            return INT_MAX-200;
        
        if(dp[row][col]!=-1)
            return dp[row][col];
         int x =grid[row][col];
         grid[row][col] =-1;
        int p=0;
        int q=0;
         p= x+solve(row+1,col,grid,dp);
         q =x+solve(row,col+1,grid,dp);
        grid[row][col]=x;
            
        
        return  dp[row][col]=min(p,q);
    }
};