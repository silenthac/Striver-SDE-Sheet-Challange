class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        int n =nums.size();
        vector<int>temp;
        unordered_set<int>st;
        solve(nums,n,temp,st);
        return ans;
        
        
    }
    
    
    void solve(vector<int>&nums,int n,vector<int>&temp,unordered_set<int>&st)
    {
        
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i])==st.end())
            {
                st.insert(nums[i]);
                temp.push_back(nums[i]);
                solve(nums,n,temp,st);
                st.erase(nums[i]);
                temp.pop_back();
            }
        }
    }
    
    
};