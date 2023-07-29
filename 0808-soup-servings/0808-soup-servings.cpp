class Solution {
public:
    double soupServings(int n) {
        if(n>5000)
        {
            return 1.0;
        }
         int countA=n;
        int countB =n;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1.0));

        return  solve(countA,countB,dp);
        
    }
    
    
    
    double solve(int countA,int countB,vector<vector<double>>&dp)
    {
        
        if(countA<=0&&countB<=0)
        {
            return 0.5;
        }
        
        if(countA<=0)
        {
            return 1.0;
        }
        
        if(countB<=0)
        {
            return 0.0;
        }
        
        if(dp[countA][countB]!=-1)
        {
            return dp[countA][countB];
        }
        
        
        return  dp[countA][countB] = 0.25*(solve(countA-100,countB-0,dp)+solve(countA-75,countB-25,dp)+solve(countA-50,countB-50,dp)+solve(countA-25,countB-75,dp));
    }
};