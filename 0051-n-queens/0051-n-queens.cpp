class Solution {
public:
    
    vector<vector<string>>ans;
    
    
    
    
    bool isSafe(int row,int col,vector<string>&grid)
    {
        int temp_row=row;
        int temp_col =col;
        int n=grid.size();
        
        while(temp_row>=0&&temp_col>=0)
        {
            if(grid[temp_row--][temp_col--]=='Q')
                return false;
            
            
        }
        temp_row=row;
        temp_col=col;
        while(temp_col>=0&&temp_row<n)
        {
            if(grid[temp_row++][temp_col--]=='Q')
                return false;
        }
        
        temp_row=row;
        temp_col=col;
        
        while(temp_col>=0)
        {
            if(grid[temp_row][temp_col--]=='Q')
            {
                return false;
            }
        }
        
         temp_row=row;
        temp_col=col;
        
        while(temp_row>=0)
        {
            if(grid[temp_row--][temp_col]=='Q')
            {
                return false;
            }
            
        }
        
        
        
        return true;
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>grid(n,string(n,'.'));
        solve(0,grid);
        return ans;
          
        
    }
    
    void solve(int col,vector<string>grid)
    {
        int n =grid.size();
        if(col==n)
        {
            ans.push_back(grid);
            return;
        }
        
        int row=0;
        while(row<n)
        {
            if(isSafe(row,col,grid))
            {
                grid[row][col] ='Q';
                solve(col+1,grid);
                grid[row][col] ='.';
            }
            row++;
        }
    }
};