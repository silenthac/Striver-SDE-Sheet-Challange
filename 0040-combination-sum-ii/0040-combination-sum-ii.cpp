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
        
        temp.push_back(nums[i]);
        solve(i+1,nums,target-nums[i],temp);
        temp.pop_back();
        while(i+1<nums.size()&&nums[i]==nums[i+1])
        {
            i++;
        }
        solve(i+1,nums,target,temp);
     
          
          
      
        
       
        
        
        
        
        
        
        
     }
};