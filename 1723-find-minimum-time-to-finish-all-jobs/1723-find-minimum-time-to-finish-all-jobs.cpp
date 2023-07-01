class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int>vec(k,0);
        int ans = INT_MAX;
        solve(0,jobs,k,vec,ans);
        return ans;
        
        
        
        
    }
    
    
    void solve(int start,vector<int>&jobs,int k,vector<int>&vec,int &ans)
    {
        
        
        if(start==jobs.size())
        {
            int tempans = INT_MIN;
            
            for(int  i=0;i<vec.size();i++)
            {
                tempans= max(tempans,vec[i]);
            }
            
            ans = min(ans,tempans);
            return;
            
            
        }
        
        
        for(int i=0;i<k;i++)
        {
            if(i>0&&vec[i-1]==vec[i])
            {
                continue;
            }
            if(vec[i]+jobs[start]>ans)
            {
                continue;
            }
            vec[i]+=jobs[start];
            solve(start+1,jobs,k,vec,ans);
            vec[i] = vec[i]-jobs[start];
        }
        
    }
};