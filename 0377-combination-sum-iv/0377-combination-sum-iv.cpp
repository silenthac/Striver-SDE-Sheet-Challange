class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        
        return solve(nums,target,dp);
        
    }
    
    int solve(vector<int>&nums,int target,vector<int>&dp)
    {
        if(target<0)
        {
            return 0;
        }
        
        if(target==0)
        {
            return 1;
        }
        
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        
        int prev=0;
        for(int i=0;i<nums.size();i++)
        {
            prev = prev+solve(nums,target-nums[i],dp);
        }
        
        return dp[target] =  prev;
    }
};