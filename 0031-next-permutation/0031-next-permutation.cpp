class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n =nums.size();
        int i;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]>=nums[i+1])
            {
                continue;
            }
            else
            {
                break;
            }
        }
        
        if(i==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
            
        }
        else
        {
            int j;
            for( j=n-1;j>=0;j--)
            {
                if(nums[j]>nums[i])
                break;
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
        
        
        
    }
};