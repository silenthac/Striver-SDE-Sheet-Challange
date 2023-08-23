class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        double n = s.size();
        int ceilit = (ceil)(n/2.0);
        string  ans ="";
        int t = INT_MIN;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]>ceilit)
            {
                return "";
            }
            
           
            
            
        }
        
       for(auto it:mp)
       {
           cout<<it.first<<" "<<it.second;
           pq.push({it.second,it.first});
       }
        
        while(pq.size()>1)
        {
            auto f = pq.top();
            pq.pop();
            auto s = pq.top();
            pq.pop();
            ans+=f.second;
            ans+=s.second;
            f.first = f.first-1;
            s.first =s.first-1;
            if(f.first>0)
            {
                pq.push(f);
            }
            if(s.first>0)
            {
                pq.push(s);
            }
            
            
            
        }
        
        if(pq.empty())
        {
            return ans;
        }
        
        if(pq.top().first==1)
        {
            ans+=pq.top().second;
            return ans;
        }
        else
        {
            return "";
        }
        
       
        
        
        
        
       
        
       
        
        
        

        
        
        
        
        
        
        
        
    }
};