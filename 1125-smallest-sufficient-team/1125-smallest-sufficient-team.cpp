
int dp[1 << 16][64];
bool choice[1 << 16][64];
class Solution {
public:
    int m;
    int req_mask;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=req_skills.size();
        m = people.size();
        unordered_map<string,int>mp;
        for (int i = 0; i < n; ++i){
            mp[req_skills[i]] = i;}
        vector<int>people_mask;
        for(int i=0;i<people.size();i++)
        {
            int mask =0;
            for(int j=0;j<people[i].size();j++)
            {
                mask = mask|(1<<mp[people[i][j]]);
                
            }
            people_mask.push_back(mask);
        }
         memset(dp, -1, 1<<n+8);
        memset(choice, 0, 1<<n+6);
        req_mask  =(1<<n)-1;
       // cout<<req_mask<<endl;
       int res = solve(0,people_mask,0);
       // cout<<res;
       vector<int> ans;
        for (int i = 0, mask = 0; i < m; ++i) {
            // did we include the i'th person?
            if (choice[mask][i]) {
                ans.push_back(i);
                mask |= people_mask[i];
            }
            
            if (mask == req_mask)
                break;
        }
        
        return ans;
        
        
        
       
        
    }
    
    int solve(int i,vector<int>&people,int mask)
    {
        if(mask==req_mask)
        {
            return 0;
        }
        
        if(i==m)
        {
            return 10000;
        }
         int &ans = dp[mask][i];
         if (ans != -1)
            return ans;
       
        
        int ans1= solve(i+1,people,mask|people[i])+1;
        int ans2 = solve(i+1,people,mask);
        
        if(ans1<ans2)
        {
          choice[mask][i]=1;  
        }
        
        return  ans=min(ans1,ans2);
    }
};