class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        vector<int>dp1(nums.size(),1);
        int maxi=0;
        int result=0;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i] = dp[j]+1;
                        dp1[i]  =dp1[j];
                    }
                    
                    else if(dp[j]+1==dp[i])
                    {
                        dp1[i]+=dp1[j];
                    }
                    
                   
                }
                
                
            }  
        }
        
       int maxlen = *max_element(dp.begin(),dp.end());
        int res=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(dp[i]==maxlen)
            {
                res+=dp1[i];
            }
        }
        return res;
        
    }
};