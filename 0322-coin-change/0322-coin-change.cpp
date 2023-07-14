class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        
        int ans =  solve(0,coins,amount,dp);
        if(ans==INT_MAX-1)
            return -1;
        return ans;
        
    }
    
    int solve(int i,vector<int>&coins,int amount,vector<vector<int>>&dp)
    {
        if(amount==0)
            return 0;
        if(i==coins.size())
        {
            return INT_MAX-1;
            
        }
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int taken = INT_MAX;
        
        int nottaken = solve(i+1,coins,amount,dp);
        
        if(amount-coins[i]>=0)
        {
            taken = 1+solve(i,coins,amount-coins[i],dp);
            
        }
        
        return  dp[i][amount] = min(taken,nottaken);
    }
};