class Solution {
public:
    
    vector<int>prefixArray(string s)
    {
        int n = s.size();
        vector<int>p(n,0);
        
        for(int i=1;i<n;i++)
        {
            int j = p[i-1];
            while(j>0&&s[i]!=s[j])
            {
                j = p[j-1];
                
            }
            
            if(s[i]==s[j])
            {
                j++;
            }
            
            p[i] =j;
        }
        return p;
    }
    
    
    
    int strStr(string t, string s) {
        
        
        vector<int>prefix = prefixArray(s);
        int pos =-1;
        int i=0;
        int j=0;
        while(i<t.size())
        {
            if(t[i]==s[j])
            {
                j++;
                i++;
            }
            
            else
            {
                if(j!=0)
                {
                    j = prefix[j-1];
                }
                else
                {
                    i++;
                }
            }
            
            if(j==s.size())
            {
                pos =i-s.size();
                break;
            }
        }
        return pos;
        
        
    }
};