//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int mod = 100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int>dp(mod,-1);
        queue<int>pq;
        pq.push(start);
        dp[start]=0;
        if(start==end)
        return 0;
        while(!pq.empty())
        {
            auto cur = pq.front();
            pq.pop();
        
        
        for(int i=0;i<arr.size();i++)
        {
            int next = (cur*arr[i])%mod;
            // if(next>end) continue;
            
            if(dp[next]==-1)
            {
                dp[next] = dp[cur]+1;
                pq.push(next);
            }
            
            if(next==end)
            {
                return dp[next];
            }
            
        }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends