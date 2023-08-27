class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,int>mp;
        int n = stones.size();
        for(int i=0;i<stones.size();i++)
        {
            mp[stones[i]] = i;
        }
        
         vector<vector<int>>dp(stones.size()+1,vector<int>(n,-1));
        
        return solve(0,stones,0,mp,dp);
        
    }
    
    
    bool solve(int index,vector<int>&stones,int k,unordered_map<int,int>&mp,vector<vector<int>>&dp)
    {
        if(index==stones.size()-1)
        {
            return true;
        }
        
        if(index>=stones.size())
        {
            return false;
        }
        
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        bool flag =false;
        for(int i=k-1;i<=(k+1);i++)
        {
            if(i<0)
            {
                continue;
            }
            if(mp.find(stones[index]+i)!=mp.end()&&mp[stones[index]+i]>index)
            {
                flag = flag|solve(mp[stones[index]+i],stones,i,mp,dp);
            }
            
           
        }
        return dp[index][k] = flag;
    }
};