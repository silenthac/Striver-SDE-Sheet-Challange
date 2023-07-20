class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         solve(image[sr][sc],sr,sc,image,color);
         return image;
        
    }

    void solve(int initial,int row,int col,vector<vector<int>>& image,int color)
    {
        if(row<0||row>=image.size()||col<0||col>=image[0].size())
        return;
        if(image[row][col]!=initial||image[row][col]==color)
        return;
        image[row][col] =color;
        solve(initial,row+1,col,image,color);
        solve(initial,row,col+1,image,color);
        solve(initial,row-1,col,image,color);
        solve(initial,row,col-1,image,color);


       

    }
};