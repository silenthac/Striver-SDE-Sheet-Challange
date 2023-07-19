class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer>mp = new HashMap<>();
        int arr[] = new int[2];
        
        for(int i=0;i<nums.length;i++)
        {
            if(mp.get(target-nums[i])==null)
            {
                mp.put(nums[i],i);
            }
            else
            {
                int ele =mp.get(target-nums[i]);
                 arr[0] =ele;
                arr[1] =i;
                
            }
            
        }
        return arr;
        
        
    }
}