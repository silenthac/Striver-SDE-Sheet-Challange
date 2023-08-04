class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n =s.size();
        set<string>st(wordDict.begin(),wordDict.end());
        vector<bool>dp(n,false);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                string temps = s.substr(j,i-j+1);
                
                if(st.find(temps)!=st.end())
                {
                    if(j==0)
                    {
                        dp[i] =true;
                    }
                    else
                    {
                        dp[i]  = dp[i]||dp[j-1];
                    }
                    
                }
                
            }
        }
        return dp[n-1];
        
    }
};