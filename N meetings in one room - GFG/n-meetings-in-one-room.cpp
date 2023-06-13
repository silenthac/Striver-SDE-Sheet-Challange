//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
      static  bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.second<b.second)
        return true;
        else
        return false;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>vec;
        
        for(int i=0;i<n;i++)
        {
            vec.push_back({start[i],end[i]});
        }
        
        sort(vec.begin(),vec.end(),comp);
        
        int ans=1;
        int ele = vec[0].second;
        for(int j=1;j<n;j++)
        {
            if(vec[j].first>ele)
            {
                ans++;
                ele = vec[j].second;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends