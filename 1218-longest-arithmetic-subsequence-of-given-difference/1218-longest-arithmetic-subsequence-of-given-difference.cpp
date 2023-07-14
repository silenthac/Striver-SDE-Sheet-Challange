class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int>mp;
        int ans=1;
     
        
        for(int i=0;i<arr.size();i++)
        {
            if(mp.find(arr[i]-diff)!=mp.end())
            {
                mp[arr[i]] = mp[arr[i]-diff]+1;
            }
            else
            {
                mp[arr[i]] =1;
            }
            
            ans =max(ans,mp[arr[i]]);
          
        }
        return ans;
        
    }
};