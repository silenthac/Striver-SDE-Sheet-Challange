class Solution {
public:
    int myAtoi(string s) {
        
        long long res =0;
        int i = 0,len = s.length();
        bool neg = false;
        
        while(s[i]==' ')i++;
        if(s[i]=='+') i++;
        else if(s[i]=='-') {i++;neg = true;}
        
        while(s[i]>='0' && s[i]<='9')
        {
            res = res*10 +s[i]-'0';
            
            if(res>=INT_MAX && !neg)
            {
                res = INT_MAX;
                break;
            }
            else if(res>INT_MAX && neg)
            {
                res = INT_MIN;
                break;
            }
            i++;
            
        }
        
        if(neg) res*=-1;
        return (int)res;
        
        
    }
};