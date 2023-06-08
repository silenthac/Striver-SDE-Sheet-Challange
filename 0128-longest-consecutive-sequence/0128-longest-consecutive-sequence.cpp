class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        int ans=0;
        for(auto it:nums)
        {
            st.insert(it);
        }
        for(auto it:nums)
        {
            if(st.find(it)==st.end())
            {
                continue;
            }
            cout<<it<<" ";
          //  st.erase(it);
            int prev = it-1;
            int next = it+1;
            while(st.find(prev)!=st.end())
            {
                st.erase(prev);
                prev--;
            }
            
            while(st.find(next)!=st.end())
            {
                st.erase(next);
                next++;
            }
            ans =max(ans,((next-prev)-1));
            
        }
        return ans;
        
      
        
    }
};