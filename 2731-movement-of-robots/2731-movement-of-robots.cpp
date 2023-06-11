class Solution {
public:
    int m= 1e9+7;
    int sumDistance(vector<int>& nums, string s, int d) {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='R')
            {
                nums[i]+=d;
            }
            else
            {
                nums[i] = nums[i]-d;
            }
        }
        
        sort(nums.begin(),nums.end());
        long long presum=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans =  ans+ ((i* (long long)nums[i]) -presum);
            ans = ans%m;
            presum= (presum+nums[i]);
            
        }
        return ans;
        
        
        
        
    }
};