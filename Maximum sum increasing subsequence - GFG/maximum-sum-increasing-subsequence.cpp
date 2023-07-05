//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>>dp(n,vector<int>(n+1,-1));
	    return solve(0,-1,arr,n,dp);
	}  
	
	
	
	int solve(int currindex,int prevind,int arr[],int n,vector<vector<int>>&dp)
	{
	    if(currindex==n)
	    return 0;
	    
	    if(dp[currindex][prevind+1]!=-1)
	    {
	        return dp[currindex][prevind+1];
	        
	    }
	    
	    
	    
	    int notaken  = solve(currindex+1,prevind,arr,n,dp);
	   int taken=0;
	   //int notaken=0;
	    if(prevind==-1||arr[currindex]>arr[prevind])
	    {
	     taken = arr[currindex]+solve(currindex+1,currindex,arr,n,dp);
	    }
	   // else
	   // {
	   //     notaken  = solve(currindex+1,prevind,arr,n);
	   // }
	    
	    return  dp[currindex][prevind+1] =max(taken,notaken);
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends