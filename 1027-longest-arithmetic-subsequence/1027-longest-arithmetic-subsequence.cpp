class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
    int n =nums.size();
        int ans=0;
        unordered_map<int,int>mp[n+1];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int cnt=1;
                int diff = nums[i]-nums[j];
                
                if(mp[j].count(diff))
                {
                    cnt=mp[j][diff];
                }
                
                mp[i][diff] = 1+cnt;
                ans = max(ans,mp[i][diff]);
            }
        }
        return ans;
    }
};