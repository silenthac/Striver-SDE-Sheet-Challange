class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0;
        int j=0;
        int ans =0;
        set<char>st;
        while(j<n)
        {
            if(st.find(s[j])==st.end())
            {
            st.insert(s[j]);
                j++;
                ans =max(ans,j-i);
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
        
    }
};