class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i =0;
        int n =nums.size();
        
        bool allone =true;
        while(i<n)
        {
            if(nums[i]==0)
            {
                allone=false;
                i++;
                
            }
            else
            {
                break;
            }
        }
        
        if(i==n)
            return 0;
        int count=0;
        
        vector<int>vec;
        while(i<n)
        {
            
             if(nums[i]==1)
            {
                count++;
            }
            
            else
            {
                vec.push_back(count);
                count=0;
                allone =false;
                //zeropresent =true;
            }
            i++;
        }
        
        if(count>0)
        {
            vec.push_back(count);
        }
        
        if(vec.size()==0)
            return 0;
        
        if(vec.size()==1)
        {
            if(allone==true)
            {
                return (vec[0]-1);
            }
            else
            {
                return vec[0];
            }
        }
        
        
      
        
        int ans=0;
        
        
        
        for(int i=0;i<vec.size()-1;i++)
        {
            ans =max(ans,(vec[i]+vec[i+1]));
        }
        return ans;
        
    }
};