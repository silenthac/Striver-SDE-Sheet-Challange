class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        
        solve(0,nums,target,temp);
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
      for(int index = i;index<nums.size();index++)
      {
          if(index>i&&nums[index]==nums[index-1])
          {
              continue;
          }
          temp.push_back(nums[index]);
          
          solve(index+1,nums,target-nums[index],temp);
          temp.pop_back();
          
          
      }
        
       
        
        
        
        
        
        
        
     }
};