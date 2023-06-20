class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        int i=0;
        int  j=0;
        vector<int>vec;
        while(j<nums.size())
        {
            pq.push({nums[j],j});
           if((j-i)+1<k)
           {
               
               j++;
           }
            else if((j-i+1)==k)
            {
                while(!pq.empty()&&pq.top().second<i)
                {
                    pq.pop();
                }
                
                vec.push_back(pq.top().first);
                i++;
                 if(j<nums.size()){
                 pq.push({nums[j],j});
                j++;
                 }
                 
                

            }
            
        }
        return vec;
        
    }
};