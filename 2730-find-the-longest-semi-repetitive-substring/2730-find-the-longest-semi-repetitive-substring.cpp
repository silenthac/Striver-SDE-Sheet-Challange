class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n =s.size();
        vector<int>dp(s.size()+1,-1);
        int ans=0;
        solve(0,s,ans,dp);
        return ans;
        
    }
    
    
    void solve(int i,string s,int &ans,vector<int>&dp)
    {
        if(i==s.size())
            return;
        
        if(dp[i]!=-1){
            ans =  max(dp[i],ans);
            return;
        }
        
        
        
        for(int ind=i;ind<s.size();ind++)
        {
            if(check(s.substr(i,ind-i+1)))
            {
                ans = max(ans,ind-i+1);
                dp[i] =max(ans,dp[i]);
                    
            }
            
            solve(ind+1,s,ans,dp);
           
        }
    }

    
    bool check(string s)
    {
        int count=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                count++;
            }
        }
        
        if(count<=1)
            return true;
        else
            return false;
    }
};