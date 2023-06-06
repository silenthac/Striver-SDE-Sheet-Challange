class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int ele= abs(nums[i]);
            if(nums[ele]<0)
            {
                return ele;
            }
            else
            {
                nums[ele] = -nums[ele];
            }
            
        }
        return 0;
        
    }
};