class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        
        for(int  i=0;i<32;i++)
        {
            int count=0;
            
            for(int j=0;j<nums.size();j++)
            {
                if(((nums[j]>>i)&1)==1)
                {
                    count++;
                count =count%3;
                }
            }
            
           // count = count%3;
            
            if(count!=0)
            {
                ans |= count<<i;
            }
            
            
        }
        return ans;
        
    }
};