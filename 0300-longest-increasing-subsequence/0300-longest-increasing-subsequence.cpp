//We can  do it in brute force manner simply check wheher the prevous all element are smaller than current element or not if yes then taken max of those previous element

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       
        vector<int>vec(n,1);
        
        for(int i=0;i<n;i++)
        {
            int maxi =0;
            
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    maxi =max(maxi,vec[j]);
                }
            }
            
            vec[i]= maxi+vec[i];
        }
        
        return *max_element(vec.begin(),vec.end());
        
        
        
        
        
    }
};