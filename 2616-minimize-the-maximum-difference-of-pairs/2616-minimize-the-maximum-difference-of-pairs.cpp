//this question is a blend of greedy and binary search the main condition of this question is we have to find p number of pairs who difference is less than

class Solution {
public:
    
    bool isGood(vector<int>nums,int mid,int p)
    {
        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]-nums[i]<=mid)
            {
                count++;
                i++;
                
            }
            
            
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low=-1;
        int high = nums[n-1]-nums[0];
        while(high-low>1)
        {
            int mid=low+(high-low)/2;
            
            if(isGood(nums,mid,p))
            {
                high =mid;
            }
            else
            {
                low =mid;
            }
        }
        return high;
        
        
        
    }
};