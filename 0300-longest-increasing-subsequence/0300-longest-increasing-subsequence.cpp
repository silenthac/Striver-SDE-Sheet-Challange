class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        
        return solve(0,-1,nums,dp);
        
    }
    
    
    int solve(int currind,int prevInd,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(currind==nums.size())
            return 0;
        
        if(dp[currind][prevInd+1]!=-1)
            return dp[currind][prevInd+1];
        
        
        int taken=0;
        if(prevInd==-1||nums[currind]>nums[prevInd])
        {
            taken =  1+solve(currind+1,currind,nums,dp);
        }
        
        int notaken =  solve(currind+1,prevInd,nums,dp);
        return  dp[currind][prevInd+1] = max(taken,notaken);
        
    }
};