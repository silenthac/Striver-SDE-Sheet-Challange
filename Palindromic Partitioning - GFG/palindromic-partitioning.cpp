//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        vector<vector<bool>>dp(str.size(),vector<bool>(str.size()));
        
        for(int g=0;g<str.size();g++)
        {
            for(int i=0,j=g;j<str.size();j++,i++)
            {
                if(g==0)
                {
                    dp[i][j] = true;
                }
                else if(g==1)
                {
                    if(str[i]==str[j])
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
                    if(str[i]==str[j]&&dp[i+1][j-1]==true)
                    {
                        dp[i][j] =true;
                    }
                    else
                    {
                        dp[i][j] =false;
                    }
                   
                }
                
            }
        }
        
        vector<int>dp1(str.size());
        dp1[0] =0;
        
        for(int j=0;j<str.size();j++)
        {
            if(dp[0][j])
            {
               dp1[j]=0;
            }
            else
            {
                int mini =INT_MAX;
                for(int i=j;i>=1;i--)
                {
                    if(dp[i][j])
                    {
                        if(dp1[i-1]<mini)
                        {
                            mini = dp1[i-1];
                        }
                        
                    }
                }
                
                dp1[j] = mini+1;
            }
        }
        return dp1[str.size()-1];
        
        // for(int g=0;g<str.size();g++)
        // {
        //     for(int i=0,j=g;j<str.size();j++,i++)
        //     {
        //         if(g==0)
        //         {
        //             dp1[i][j]=0;
        //         }
        //         else if(g==1)
        //         {
        //             if(str[i]==str[j])
        //             {
        //                 dp1[i][j]=0;
        //             }
        //             else
        //             {
        //                 dp1[i][j]=1;
        //             }
                    
        //         }
        //         else
        //         {
        //             if(dp[i][j])
        //             {
        //                 dp1[i][j]=0;
        //             }
        //             else
        //             {
        //             int mini = INT_MAX;
        //             for(int k=i;k<j;k++)
        //             {
                       
        //               int left = dp1[i][k];
        //               int right =dp1[k+1][j];
        //               if(left+right+1<mini)
        //               {
        //                   mini =left+right+1;
        //               }
        //             }
        //             dp1[i][j]  =mini;
        //             }
                    
        //         }
        //     }
        // }
        
        // return dp1[0][str.size()-1];
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends