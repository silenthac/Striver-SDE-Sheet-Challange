//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>res;
        int sum=0;
        solve(0,arr,N,res,0);
        return res;
    }
    
    
    void solve(int i,vector<int>arr,int n,vector<int>&res,int sum)
    {
        if(i==n)
        {
            res.push_back(sum);
            return;
        }
        
        solve(i+1,arr,n,res,sum);
        solve(i+1,arr,n,res,sum+=arr[i]);
        
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends