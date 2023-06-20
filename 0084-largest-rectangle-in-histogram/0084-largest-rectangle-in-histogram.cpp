
//hme previous smaller and next smaller element ke index ke alag alag array bnaane hai aur frr formula use krnaa hai ((right[i]-left[i])-1)*heights[i];

class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftsmaller(n);
        vector<int>rightsmaller(n);
        stack<int>stk;
        stk.push(-1);
        stk.push(0);
        leftsmaller[0] =-1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[stk.top()]<nums[i])
            {
                leftsmaller[i] = stk.top();
            }
            else
            {
                while(nums[stk.top()]>=nums[i])
                {
                    
                    stk.pop();
                    if(stk.top()==-1)
                    {
                        break;
                    }
                }
                
                leftsmaller[i] = stk.top();
                
            }
            
            stk.push(i);
        }
        while(!stk.empty())
        {
            stk.pop();
        }
        stk.push(n);
        stk.push(n-1);
        rightsmaller[n-1]=n;
        
        for(int i=n-2;i>=0;i--)
        {
            if(nums[stk.top()]<nums[i])
            {
                rightsmaller[i] = stk.top();
            }
            else
            {
                while(nums[stk.top()]>=nums[i])
                {
                    
                    stk.pop();
                    if(stk.top()==n)
                    {
                        break;
                    }
                }
                
                rightsmaller[i] = stk.top();
                
            }
            
            stk.push(i);
        }
        
       
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int tempans = (rightsmaller[i]-leftsmaller[i]-1)*nums[i];
            ans = max(ans,tempans);
            
        }
        
       
        
        
        return ans;
        
    }
};