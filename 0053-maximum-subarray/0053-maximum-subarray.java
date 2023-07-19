class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum=nums[0];
        int res=nums[0];
        
        for(int i=1;i<nums.length;i++)
        {
            if(nums[i]+maxSum<nums[i])
            {
                maxSum =nums[i];
            }
            
            else
            {
                maxSum+=nums[i];
            }
            
             res =Math.max(maxSum,res);
        }
        return res;
    }
}