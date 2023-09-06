class Solution {
public:
    
    int mod = 1e9+7;
     int nCr(int n, int r){
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
    
   
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        unordered_map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        
        vector<int>vec;
        
        for(auto it:mp)
        {
            vec.push_back(it.second);
        }
        
        sort(vec.begin(),vec.end(),greater<int>());
        
        if(vec.size()<k)
        {
            return 0;
        }
        int n=0;
        int r=0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]==vec[k-1])
            {
                n++;
            }
            
            if(i<k&&vec[i]==vec[k-1])
            {
                r++;
            }
        }
        
        long long sum = (nCr(n,r))%mod;
        
        for(int i=0;i<k;i++)
        {
            sum= ((sum%mod)*(vec[i]%mod))%mod;
        }
        
        return sum;
        
        
    }
};