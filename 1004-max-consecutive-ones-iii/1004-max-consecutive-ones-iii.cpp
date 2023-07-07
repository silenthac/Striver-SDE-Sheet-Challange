class Solution {
public:
    
    
    
    int longestOnes(vector<int>& nums, int k) {
        int n =nums.size();
        int i=0;
        int  j=0;
        int ans=0;
        while(j<n)
        {
            if(nums[j]==1)
            {
                j++;
            }
            else
            {
                if(k>0)
                {
                    j++;
                    k--;
                    
                }
                else
                {
                    ans =max(ans,j-i);
                    if(nums[i]==1)
                    {
                        i++;
                    }
                    else
                    {
                        k++;
                        i++;
                    }
                }
            }
            
        }
        ans = max(ans,j-i);
        return ans;
        
        
        
    }
};