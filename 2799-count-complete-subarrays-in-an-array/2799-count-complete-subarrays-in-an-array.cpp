class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        int s = st.size();
        int left=0;
        int right=0;
       unordered_map<int,int>mp;
        while(right<nums.size())
        {
            mp[nums[right]]++;
            
            while(left<=right&&s==mp.size())
            {
                mp[nums[left]]--;
                if(mp[nums[left]]==0)
                {
                    mp.erase(nums[left]);
                    
                }
                
                left++;
                    ans+=(nums.size()-right);
                
            }
            right++;
            
            
        }
        
        return ans;
        
        
    }
};