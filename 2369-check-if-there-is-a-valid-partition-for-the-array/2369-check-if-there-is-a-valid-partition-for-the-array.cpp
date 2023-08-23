class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n =nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,n,dp);
        
        
    }
    
    
    bool solve(int index,vector<int>&nums,int n,vector<int>&dp)
    {
        if(index>=n)
        {
            return true;
        }
        
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
        
        if(index+1<n&&nums[index]==nums[index+1])
        {
            if(solve(index+2,nums,n,dp))
            {
              return  dp[index] = true;
            }
        }
        
        if(index+2<n&&nums[index]==nums[index+1]&&nums[index+1]==nums[index+2])
        {
            if(solve(index+3,nums,n,dp))
            {
               return dp[index] =true;
            }
        }
        
        if(index+2<n&&nums[index+1]-nums[index]==1&&nums[index+2]-nums[index]==2)
        {
            if(solve(index+3,nums,n,dp))
            {
                return dp[index] =  true;
            }
        }
        
        return dp[index] =  false;
    }
};