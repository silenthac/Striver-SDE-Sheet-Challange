class Solution {
public:
    //agar usse agla chota  ya equal hai then increment and find the  value of group else  find  the value of single numberal
    int romanToInt(string s) {
        int n =s.size();
        
        unordered_map<char,int>mp;
         mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] =10;
        mp['L'] = 50;
        mp['C'] =100;
        mp['D'] = 500;
        mp['M'] =1000;
        
        int ans = mp[s[n-1]];
       for(int i=n-2;i>=0;i--)
       {
           if(mp[s[i]]<mp[s[i+1]])
           {
               ans = ans-mp[s[i]];
           }
           else
           {
               ans =ans+=mp[s[i]];
           }
       }
        return ans;
            
        
    }
};