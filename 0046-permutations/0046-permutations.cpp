class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
       // vector<bool>visited(nums.size()+1,false);
        unordered_map<int,int>mp;
        vector<int>temp;
        solve(0,nums,mp,temp);
        return ans;
        
    }
    
    
    void solve(int index,vector<int>&nums,unordered_map<int,int>&mp,vector<int>&temp)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
               temp.push_back(nums[i]);
                mp[nums[i]]++;
                solve(i+1,nums,mp,temp);
                temp.pop_back();
                mp.erase(nums[i]);
            }
        }
    }
        
     
};