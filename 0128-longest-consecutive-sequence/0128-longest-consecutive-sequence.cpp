class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0)
            return 0;
        int count=1;
        int ans=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]+1)
            {
                count++;
            }
            else if(nums[i]==nums[i-1])
            {
                continue;
            }
            else
            {
                ans=max(ans,count);
                count=1;
                
            }
        }
        ans =max(ans,count);
        return ans;
        
    }
};