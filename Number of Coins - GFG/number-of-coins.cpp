//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    
	    vector<vector<int>>dp(M+1, vector<int>(V+1,-1));
	    int ans= solve(0,coins,M,V,dp);
	    if(ans==INT_MAX-1)
	    return -1;
	    return ans;
	     
	} 
	
	
	int solve(int i,int coins[], int M,int V,vector<vector<int>>&dp)
	{
	    if(i==M||V<0)
	    {
	       return INT_MAX-1; 
	    }
	    
	    if(V==0)
	    return 0;
	    
	    if(dp[i][V]!=-1)
	    return dp[i][V];
	    
	    int notaken =solve(i+1,coins,M,V,dp);
	    
	    int taken = min(1+solve(i,coins,M,V-coins[i],dp),solve(i+1,coins,M,V,dp));
	    return dp[i][V] = min(taken,notaken);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends