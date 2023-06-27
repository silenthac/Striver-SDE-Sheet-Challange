class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        set<pair<int,int>>st;
        
        pq.push({nums1[0]+nums2[0],{0,0}});
        st.insert({0,0});
        
        while(!pq.empty()&&k)
        {
            int index1= pq.top().second.first;
            int index2 = pq.top().second.second;
            ans.push_back({nums1[index1],nums2[index2]});
            int sum = pq.top().first;
            pq.pop();
            
            if(index1+1<nums1.size()&&st.find({index1+1,index2})==st.end())
            {
                pq.push({nums1[index1+1]+nums2[index2],{index1+1,index2}});
                st.insert({index1+1,index2});
                
            }
            
            if(index2+1<nums2.size()&&st.find({index1,index2+1})==st.end())
            {
                pq.push({nums1[index1]+nums2[index2+1],{index1,index2+1}});
                st.insert({index1,index2+1});
                
            }
            k--;
            
            
        }
        return ans;
        
    }
};