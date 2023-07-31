class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m =s1.size();
        int n =s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        return solve(s1,s2,m-1,n-1,dp);
        
        
    }
    
    
    int findASCII(int size,string s)
    {
        int ans=0;
        for(int i=0;i<=size;i++)
        {
            ans+=int(s[i]);
        }
        return ans;
    }
    
    int solve(string &s1,string &s2,int m,int n,vector<vector<int>>&dp)
    {
        if(m<0&&n<0)
            return 0;
        if(m<0)
        {
            return findASCII(n,s2);
        }
        if(n<0)
        {
            return findASCII(m,s1);
        }
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        if(s1[m]==s2[n])
        {
            return dp[m][n] = solve(s1,s2,m-1,n-1,dp);
        }
        else
        {
            return dp[m][n] = min(int(s1[m])+solve(s1,s2,m-1,n,dp),int(s2[n])+solve(s1,s2,m,n-1,dp));
        }
            
    }
};