class Solution {
public:
    
    static bool comp(vector<int>a,vector<int>b)
    {
        if(a[0]<b[0])
        {
            return true;
        }
        
        else if(a[0]==b[0])
        {
            if(a[1]<b[1])
                return true;
        }
        return false;
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int>dp(offers.size(),-1);
        
        sort(offers.begin(),offers.end(),comp);
        
        return solve(0,offers,-1,dp);
        
        
    }
    
    
    int solve(int index,vector<vector<int>>& offers,int prev,vector<int>&dp)
    {
        if(index==offers.size())
        {
            return 0;
        }
        
        if(dp[index]!=-1)
        {
            return dp[index];
            
        }
        
        
        int notaken =  solve(index+1,offers,prev,dp);
        int taken=0;
        
        
            int low = index+1;
            int high = offers.size()-1;
            int next_idx = offers.size();
            while(low<=high)
            {
                int mid= low+(high-low)/2;
                
                if(offers[mid][0]<=offers[index][1])
                {
                    low =mid+1;
                    
                }
                else
                {
                    next_idx = mid;
                    high = mid-1;
                }
                
            }
             taken = offers[index][2]+solve(next_idx,offers,index,dp);
        
        return dp[index] = max(taken,notaken);
    }
};