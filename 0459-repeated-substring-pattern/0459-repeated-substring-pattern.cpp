class Solution {
public:
    
    
    bool isGood(string s,string temps)
    {
        int tempn = temps.size();
        int n = s.size();
        int count = n/tempn;
        string newtemp ="";
        while(count--)
        {
            newtemp+=temps;
           
        }
        
        
        
        return newtemp==s;
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        // if(n%2)
        // {
        //     return false;
        // }
        int i=0;
        int j=0;
        while(j<n)
        {
            string temps = s.substr(i,j-i+1);
           
            
            if(temps==s)
            {
                return false;
            }
            if(isGood(s,temps))
            {
                return true;
                
            }
            j++;
        }
        return false;
        
    }
};