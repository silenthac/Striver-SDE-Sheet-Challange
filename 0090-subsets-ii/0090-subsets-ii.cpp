class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,nums,st,temp);
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
        
        
        
    }
    
    void solve(int index,vector<int>&nums,set<vector<int>>&st,vector<int>temp)
    {
        
        if(index==nums.size())
        {
            st.insert(temp);
            return;
        }
        
        solve(index+1,nums,st,temp);
        temp.push_back(nums[index]);
        solve(index+1,nums,st,temp);
        
    }

};