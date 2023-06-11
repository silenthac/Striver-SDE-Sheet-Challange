class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int i=0;
        int j=0;
        int n = s.size();
        int ans=0;
        while(j<n)
        {
            if(check(s.substr(i,j-i+1)))
            {
                ans = max(ans,j-i+1);
                j++;
                    
            }
            else
            {
                i++;
            }
        }
        return ans;
        
        
    }
    
    
    bool check(string s)
    {
        int count=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                count++;
            }
        }
        if(count<=1)
            return  true;
        else
        {
            return false;
        }
    }
};