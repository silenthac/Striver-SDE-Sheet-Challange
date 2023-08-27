class Solution {
public:
    int maxConsecutiveAnswers(string nums, int k) {
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int n = nums.size();
        int ans=0;
        int maxfreq=0;
        while(j<n)
        {
            mp[nums[j]]++;
           
            maxfreq = max(maxfreq,mp[nums[j]]);
            while((j-i+1)-maxfreq>k)
            {
                mp[nums[i]]--;
                i++;
            }
             ans =  max(ans,j-i+1);
              j++;
        }
        return ans;
        
    }
};