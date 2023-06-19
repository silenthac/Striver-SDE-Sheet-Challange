class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>vec;
        for(auto it:nums)
        {
            mp[it]++;
        }
        
       
        priority_queue<pair<int,int>>pq;
        
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
       
        while(k--)
        {
            auto top = pq.top();
            vec.push_back(top.second);
            pq.pop();
        }
        return vec;
       
        
        
    }
};