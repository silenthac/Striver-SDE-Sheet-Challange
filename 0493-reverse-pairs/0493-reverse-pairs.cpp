class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
    
    
    int solve(vector<int>&nums,int low,int high)
    {
           if(low>=high)
               return 0;
        
            int mid = low+(high-low)/2;
            int ans=solve(nums,low,mid);
            ans+=solve(nums,mid+1,high);
            ans+=merge(nums,low,mid,high);
        
        return ans;
        
    
    }
    
    int merge(vector<int>&nums,int low,int mid,int high)
    {
        int ans=0;
        int left = low;
        int right =mid+1;
        vector<int>temp;
        int j =mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(j<=high&&(nums[i]>2*1LL*nums[j]))
            {
                j++;
            }
            ans+=(j-(mid+1));
        }
        
        while(left<=mid&&right<=high)
        {
           if(nums[left]<=nums[right])
           {
               temp.push_back(nums[left]);
               left++;
               
           }
            else
            {
                // if(nums[left]>(2*nums[right]))
                // {
                //     ans+=(high-right)+1;
                // }
                temp.push_back(nums[right]);
                right++;
            }
        }
        
        while(left<=mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        
        while(right<=high)
        {
            temp.push_back(nums[right]);
            right++;
        }
        
        for(int i=low;i<=high;i++)
        {
            nums[i] = temp[i-low];
        }
        return ans;
    }
     
};