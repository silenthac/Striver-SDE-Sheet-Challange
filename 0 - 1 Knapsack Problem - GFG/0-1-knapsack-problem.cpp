//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return solve(0,W,wt,val,n,dp);
    }
    
    int solve(int index,int W,int wt[],int val[],int n,vector<vector<int>>&dp)
    {
        
        if(index==n||W==0)
        return 0;
        
        if(dp[index][W]!=-1)
        return dp[index][W];
        
        int taken=0;
        int notaken;
        notaken = solve(index+1,W,wt,val,n,dp);
        if(W>=wt[index])
         taken = val[index]+solve(index+1,W-wt[index],wt,val,n,dp);
         
        
        
         
      
        
        return dp[index][W] =  max(taken,notaken);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends