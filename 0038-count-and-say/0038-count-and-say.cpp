class Solution {
public:
    
    
    string solve(string ans)
    {
        char ch = ans[0];
        int freq =1;
		string tempans ="";
        for(int i=1;i<ans.size();i++)
        {
            if(ch==ans[i])
            {
                freq++;
            }
            else
            {
                char chfreq = (char)('0'+freq);
                tempans.push_back(chfreq);
                tempans.push_back(ch);
                ch = ans[i];
                freq=1;
            }
        }
         char chfreq = char(freq+'0');
                tempans.push_back(chfreq);
                tempans.push_back(ch);
        
        return tempans;
        
        
    }
    
   
    string countAndSay(int n) {
        
        string ans ="1";
        
        for(int i=0;i<n-1;i++)
        {
            ans = solve(ans);
        }
        
        return ans;
        
       
        
        
    }
    
    
  
};