class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>>dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        
        
        sort(cuts.begin(),cuts.end());
        return solve(1,c,cuts,dp);
        
        
    }
    
    int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>j)
            return 0;
        int mini = INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int k=i;k<=j;k++)
        {
            
        int cost= (cuts[j+1]-cuts[i-1])+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
            mini = min(cost,mini);
        }
        return dp[i][j] =  mini;
        
                          
            
        
        
        
    }
};