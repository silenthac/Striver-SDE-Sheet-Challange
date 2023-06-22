class Solution {
public:
    string reverseWords(string s) {
        stack<string>stk;
        
        stringstream ss(s);
        string word;
        while(ss>>word)
        {
            stk.push(word);
        }
        
        string res = "";
        
        while(!stk.empty())
        {
            res+=stk.top();
            stk.pop();
            if(!stk.empty())
            {
                res+=" ";
            }
        }
        return res;
        
        
        
    }
};