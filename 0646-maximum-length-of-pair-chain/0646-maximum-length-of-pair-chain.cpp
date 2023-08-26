class Solution {
public:
    
    static  bool comp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
        
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n =pairs.size();
        vector<vector<int>>dp(pairs.size()+1,vector<int>(pairs.size()+1,-1));
        
         sort(pairs.begin(),pairs.end(),comp);
        
        return solve(0,pairs,-1,dp);
        
        
        
    }
    
    
    int solve(int index,vector<vector<int>>&pairs,int prev,vector<vector<int>>&dp)
    {
        if(index==pairs.size())
        {
            return 0;
        }
        
        if(dp[index][prev+1]!=-1)
        {
            return dp[index][prev+1];
        }
        
        
        
        
        int notaken = solve(index+1,pairs,prev,dp);
        int taken=0;
        
        if(prev==-1||pairs[prev][1]<pairs[index][0])
        {
             taken = 1+solve(index+1,pairs,index,dp);
        }
        
        return  dp[index][prev+1] = max(taken,notaken);
      
    }
};