class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n  =nums.size();
        int first = INT_MAX;
        int second =INT_MAX; 
        for(int i=0;i<n;i++)
        {
            if(first>=nums[i])
            {
                first =nums[i];
            }
            else if(second>=nums[i])
            {
                second = nums[i];
            }
            else{
                
                
                return true;
            }
            
            
            
        }
        return false;
    
        
    }
};