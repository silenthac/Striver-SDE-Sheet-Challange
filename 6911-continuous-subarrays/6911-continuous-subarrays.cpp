class Solution {
public:
    
    bool isgood(multiset<int,greater<int>>&st,int ele)
    {
       
        
        int top_ele = *(st.begin());
        int below_ele = *(st.rbegin());
        
        if(top_ele-below_ele<=2)
        {
            return true;
        }
        return false;
    }
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        multiset<int,greater<int>>st;
       // multiset<int>st;
        int l=0;
        int r=-1;
        int n = nums.size();
        while(l<n)
        {
            if(r<l)
            {
                st.insert(nums[l]);
                r=l;
            }
            while(r<n&&isgood(st,nums[r]))
            {
                
                r++;
                if(r<n)
                st.insert(nums[r]);
            }
            ans+=r-l;
            st.erase(st.find(nums[l]));
            l++;
        }
        
        return ans;
        
        
    }
};