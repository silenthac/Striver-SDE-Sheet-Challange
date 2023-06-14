class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>visited(nums.size()+1,false);
        vector<int>temp;
        solve(0,nums,visited,temp);
        return ans;
        
    }
    
    
    void solve(int index,vector<int>&nums,vector<bool>&visited,vector<int>&temp)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==false)
            {
                temp.push_back(nums[i]);
                visited[i] =true;
                solve(i+1,nums,visited,temp);
                temp.pop_back();
                visited[i]=false;
            }
        }
    }
        
     
};