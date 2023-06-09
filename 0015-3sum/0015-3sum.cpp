class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            int j= i+1;
            int k = nums.size()-1;
            
            while(j<k)
            {
                int sum =nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    
                    int val1 = nums[j];
                    int val2 = nums[k];
                    
                    while(j<k&&nums[j]==val1)
                    {
                        j++;
                    }
                    
                    while(j<k&&nums[k]==val2)
                    {
                        k--;
                    }
                }
                else if(sum<0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ans;
        
    }
};