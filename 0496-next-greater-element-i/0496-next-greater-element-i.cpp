class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n =nums2.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        
        vector<int>nextgreater(n);
        stack<int>stk;
        nextgreater[n-1] = -1;
        mp[nums2[n-1]] =-1; 
        stk.push(-1);
        stk.push(nums2[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            if(!stk.empty()&&stk.top()>nums2[i])
            {
                nextgreater[i] = stk.top();
                mp[nums2[i]] = stk.top();
            }
            
            else
            {
                while(!stk.empty()&&stk.top()<=nums2[i])
                {
                    if(stk.top()==-1)
                        break;
                    stk.pop();
                    
                }
                nextgreater[i]  =stk.top();
                 mp[nums2[i]] = stk.top();
            }
            
            
            
            stk.push(nums2[i]);
            
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
        
    }
};