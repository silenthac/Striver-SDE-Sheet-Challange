class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combine(int n, int k) {
        vector<bool>vec(n+1,false);
        unordered_set<int>st;
        vector<int>temp;
        solve(1,n,k,temp,st,vec);
        return ans;
        
    }
    
    void solve(int index,int n,int k,vector<int>&temp,unordered_set<int>st,vector<bool>vec)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        
        
        for(int i=index;i<=n;i++)
        {
            if(vec[i]==false)
            {
                vec[i] =true;
                temp.push_back(i);
                solve(i+1,n,k,temp,st,vec);
                temp.pop_back();
                vec[i] =false;
            }
        }
    }
};