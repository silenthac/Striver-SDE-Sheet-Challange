class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>vec(k,0);
        int ans=INT_MAX;
        solve(0,cookies,k,vec,ans);
        return ans;
        
        
        
    }
    
    
    void solve(int start,vector<int>&cookies,int k,vector<int>&vec,int &ans)
    {
        
        if(start==cookies.size())
        {
            int  tempres = INT_MIN;
            
            for(int i=0;i<k;i++)
            {
                tempres = max(tempres,vec[i]);
            }
            
            ans =min(ans,tempres);
            return;
            
        }
        
        
        
        for(int i=0;i<k;i++)
        {
            vec[i]+=cookies[start];
            solve(start+1,cookies,k,vec,ans);
            vec[i] =vec[i]-cookies[start];
            
            
        }
        
    }
};