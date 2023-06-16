class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n =nums.size();
        if(n==1)
            return nums[0];
        int low =0;
        int high =nums.size()-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if(mid>0&&mid<n-1&&nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1])
            {
                return nums[mid];
            }
            
            else if(mid==0&&nums[mid]!=nums[mid+1])
            {
                return nums[mid];
            }
            
            else if(mid==n-1&&nums[mid]!=nums[mid-1])
            {
                return nums[mid];
            }
            
            else if(nums[mid]==nums[mid+1])
            {
                int countleft=0;
                int countright=0;
                int lefthresold = mid-1;
                int rightstart = mid+2;
                
                countleft = lefthresold+1;
                countright = nums.size()-rightstart;
                if(countleft%2!=0)
                {
                    high =mid-1;
                }
                else
                {
                    low =mid+1;
                }
                
            }
            else
            {
               int countleft=0;
                int countright=0;
                int lefthresold = mid-2;
                int rightstart = mid+1;
                
                countleft = lefthresold+1;
                countright = nums.size()-rightstart;
                if(countleft%2!=0)
                {
                    high =mid-1;
                }
                else
                {
                    low =mid+1;
                } 
            }
        }
        return -1;
        
    }
};