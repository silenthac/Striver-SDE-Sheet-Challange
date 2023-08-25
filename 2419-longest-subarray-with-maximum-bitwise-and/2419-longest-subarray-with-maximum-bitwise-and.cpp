class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        int maxi = INT_MIN;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            maxi =max(maxi,arr[i]);
            
        }
        
        int i=0;
        int j=0;
        while(j<n)
        {
            if(arr[j]!=maxi)
            {
                i=j;
                i++;
                j++;
            }
            else
            {
                j++;
                ans =max(ans,j-i);
            }
        }
        ans =max(ans,j-i);
        return ans;
            
        
        
        
       
        
    }
};