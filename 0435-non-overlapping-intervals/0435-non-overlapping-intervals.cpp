class Solution {
public:
    
    static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n= intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        
        int i=0;
        int count=-1;
        for(int j=0;j<intervals.size();j++)
        {
            if(intervals[j][0]<intervals[i][1])
            {
                count++;
                
            }
            else
            {
                i=j;
            }
        }
        
    return count;
        
    }
};