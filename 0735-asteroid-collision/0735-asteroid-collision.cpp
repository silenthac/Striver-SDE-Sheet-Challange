class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>stk;
        int n =arr.size();
        for(int i=0;i<n;i++)
        {
            if(stk.empty()||arr[i]>0)
            {
                stk.push(arr[i]);
            }
            else
            {
                while(!stk.empty()&&stk.top()>0&&stk.top()<abs(arr[i]))
                {
                    stk.pop();
                    
                }
                
                if(!stk.empty()&&stk.top()==abs(arr[i]))
                {
                    stk.pop();
                }
                
               else if(stk.empty()||stk.top()<0)
                {
                    stk.push(arr[i]);
                }
            }
        }
        
        vector<int>vec;
        while(!stk.empty())
        {
            vec.push_back(stk.top());
            stk.pop();
        }
        
        reverse(vec.begin(),vec.end());
        return vec;
        
    }
};