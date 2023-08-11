class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return solve(0,coins,amount,dp);
        
    }
    
    
    int solve(int i,vector<int>&nums,int amount,vector<vector<int>>&dp)
    {
        if(i==nums.size()||amount<0)
        {
            return 0;
        }
        
        if(amount==0)
        {
            return 1;
        }
        
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        
        
        
        
        
        
        // int nottaken = solve(i+1,nums,amount);
        // int taken = solve(i,nums,amount-nums[i]);
        
       
        
        
        
        return  dp[i][amount] =solve(i+1,nums,amount,dp)+solve(i,nums,amount-nums[i],dp);
    }
};