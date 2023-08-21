class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        
        for(int i=1;i<=n/2;i++)
        {

                if(n%i==0)
                {
                string temps = s.substr(0,i);
                
                string reps ="";
                for(int j=0;j<n/i;j++)
                {
                    reps+=temps;
                }
                
                if(reps==s)
                {
                    return true;
                }
                }
            
            
        }
        return false;
        
    }
};