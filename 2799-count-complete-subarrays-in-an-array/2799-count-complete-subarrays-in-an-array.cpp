class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        int size = st.size();
        for(int i=0;i<nums.size();i++)
        {
            unordered_set<int>st1;
            for(int j=i;j<nums.size();j++)
            {
                st1.insert(nums[j]);
                if(st1.size()==size)
                {
                    count++;
                }
                
            }
        }
        return count;
        
    }
};