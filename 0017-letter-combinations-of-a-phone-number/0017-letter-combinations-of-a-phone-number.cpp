class Solution {
public:
    vector<string>ans;
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        {
            return ans;
        }
        unordered_map<int,string>mp;
        mp[2] = "abc";
         mp[3] = "def";
        mp[4] = "ghi";
         mp[5] = "jkl";
         mp[6] = "mno";
         mp[7] = "pqrs";
         mp[8] = "tuv";
         mp[9] = "wxyz";
        
        solve(0,digits,mp,"");
        return ans;
        
             
            
        
    }
    
    void solve(int index,string &digits,unordered_map<int,string>&mp,string temp)
    {
        if(temp.size()==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        
        
        for(int i = index;i<digits.size();i++)
        {
          int t =  digits[i]-'0';
            for(auto it:mp[t])
            {
                solve(i+1,digits,mp,temp+it);
            }
            
            
        }
    }
};