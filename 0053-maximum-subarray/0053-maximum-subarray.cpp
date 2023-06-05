class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int currsum = arr[0];
        int currsofar = arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(currsum+arr[i]<arr[i])
            {
                currsum=arr[i];
            }
            else
            {
                currsum+=arr[i];
               
            }
            currsofar = max(currsum,currsofar);
        }
         
        
        return currsofar;
        
    }
};