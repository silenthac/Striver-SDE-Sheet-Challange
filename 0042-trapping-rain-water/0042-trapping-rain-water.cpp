class Solution {
public:
    int trap(vector<int>& nums) {
        int ans=0;
        int n =nums.size();
        vector<int>numsleft(n);
        vector<int>numsright(n);
        numsright[n-1]  =nums[n-1];
        numsleft[0] =nums[0];
        for(int i=1;i<nums.size();i++)
        {
            numsleft[i] = max(nums[i],numsleft[i-1]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            numsright[i] = max(nums[i],numsright[i+1]);
        }
        
        for(int  i=0;i<n;i++)
        {
            ans+=min(numsleft[i],numsright[i])-nums[i];
        }
        return ans;
        
        
        
        
    }
};