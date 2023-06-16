class Solution {
public:
    int mod=1e9+7;
    int numOfWays(vector<int>& nums) {
        
        int tot = (countBst(nums)-1)%mod;
        return tot;
        
        
    }
    
    
    int countBst(vector<int>&nums)
    {
        if(nums.size()<=2)
            return 1;
        
        
        vector<int>left;
        vector<int>right;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[0])
            {
                left.push_back(nums[i]);
            }
            else
            {
                right.push_back(nums[i]);
            }
        }
        
        long long leftcount = countBst(left);
        long long rightcount =countBst(right);
        
        long long currenttotal = BinomialCoefficient(left.size()+right.size(),left.size());
        
        return (((leftcount%mod)*(rightcount%mod))%mod*(currenttotal%mod))%mod;
    }
    
    
    
    long long BinomialCoefficient(int n,int r)
    {
        vector<vector<long long>>dp(n+1,vector<long long>(r+1,0));
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=1;
            for(int j=1;j<=min(i,r);j++)
            {
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%mod;
            }
        }
        return dp[n][r];
    }
};