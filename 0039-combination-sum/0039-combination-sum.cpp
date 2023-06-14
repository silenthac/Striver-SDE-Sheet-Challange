class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>&nums, int target) {
        sort(nums.begin(),nums.end());
        solve(0,nums,target,{});
        return ans;
        
        
    }
    
    void solve(int i,vector<int>nums,int target,vector<int>temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(i==nums.size()||target<0)
        {
            return;
        }
        
        solve(i+1,nums,target,temp);
        temp.push_back(nums[i]);
        solve(i,nums,target-nums[i],temp);
        temp.pop_back();
         
        
    }
};