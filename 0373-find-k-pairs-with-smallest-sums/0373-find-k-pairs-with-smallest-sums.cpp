class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(pq.size()<k)
                {
                    pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                }
                
                else if(pq.top().first>(nums1[i]+nums2[j]))
                {
                    pq.pop();
                    pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                }
                else
                {
                    break;
                }
            }
        }
            
            while(!pq.empty())
            {
                int  ele1=pq.top().second.first;
                int ele2 = pq.top().second.second;
                ans.push_back({ele1,ele2});
                pq.pop();
            }
            return ans;
        
        
    }
};