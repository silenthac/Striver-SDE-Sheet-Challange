class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        
        if(sum%2!=0)
        {
            return false;
        }
        
        int  target = sum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        
        
        return solve(0,nums,target,dp);
        
    }
    
    
    bool solve(int index, vector<int>&nums,int target,vector<vector<int>>&dp)
    {
        
          if(target==0)
        {
            return true;
        }
        
       
        if(index==nums.size()||target<0)
        {
            return false;
        }
        
       
        
        if(dp[index][target]!=-1)
            return dp[index][target];
        
      bool nottaken =  solve(index+1,nums,target,dp);
        
       
           
     bool taken =  solve(index+1,nums,target-nums[index],dp);
       
        
     
        return dp[index][target] =  taken||nottaken;
        
        
        
        
    }
};