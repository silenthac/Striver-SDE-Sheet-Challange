class Solution {
public:
    string longestPalindrome(string s) {
         vector<vector<int>>dp(s.size(),vector<int>(s.size()));
        int count=0;
        int ans=0;
        string  res="";
        
        for(int g=0;g<s.size();g++)
        {
            int i=0;
            int j=g;
            
            while(j<s.size())
            {
                if(g==0)
                {
                    dp[i][j]=true;
                    
                }
               
                
                
                else if(g==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j] =true;
                        
                    }
                    else
                    {
                        dp[i][j] =false;
                    }

                    
                }
            
                
                else
                {
                    if(s[i]==s[j]&&dp[i+1][j-1]==true)
                    {
                        dp[i][j] =true;
                       
                    }
                    else
                    {
                        dp[i][j] =false;
                    }
                }
                
                if(dp[i][j]==true){
                    count++;
                    if((g+1)>ans)
                    {
                        ans =g+1;
                        res = s.substr(j-g,g+1);
                    }
                }
                
                
                i++;j++;
                    
                     
            }
               
        }
       // cout<<res;
        
       
        
            return res;
        
        
    }
};