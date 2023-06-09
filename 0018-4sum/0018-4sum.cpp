class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n =nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>0&&nums[i-1]==nums[i])
            {
                continue;
            }
            
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1&&nums[j-1]==nums[j])
            {
                continue;
            }
                int k = j+1;
                int l = n-1;
                long long sum_2 = nums[i]+nums[j];
               long long x = target-(sum_2);
                while(k<l)
                {

                    
                    
                    
                    if(x==(nums[k]+nums[l]))
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l&&nums[k-1]==nums[k])
                        {
                            k++;
                        }
                        
                        while(k<l&&nums[l]==nums[l+1])
                        {
                            l--;
                        }
                    }
                    else if(x>(nums[k]+nums[l]))
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }
        return ans;
        
        
    }
};