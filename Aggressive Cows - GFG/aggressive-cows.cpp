//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:


 bool isPossible(vector<int>&a, int  n, int cows,int mid)
 {
     
     int lastStall = a[0];
     cows--;
     
     while(true)
     {
         int findval = lastStall+mid;
          int newindex = lower_bound(a.begin(), a.end(),findval)-a.begin();
         if(newindex<n)
         {
             cows--;
             if(cows==0)
             return true;
         }
         else
         {
             break;
         }
         
         lastStall =a[newindex];
     }
     
     return false;
 }

    int solve(int n, int cows, vector<int> &a) {
        sort(a.begin(),a.end());

      int low = 1, high = a[n - 1] - a[0];

      while (low <= high) {
        int mid = (low + high) >> 1;

        if (isPossible(a, n, cows, mid)) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      
    
    return high;
        
    
        
}
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends