class Solution {
public:
    int longestNiceSubarray(vector<int>& arr) {
        int AND=0;
        int i=0;
        int n =arr.size();
        int ans=0;
        for(int j=0;j<n;j++)
        {
           
            while((arr[j]&AND)!=0)
            {
                AND =AND^arr[i];
                i++;
            }
            AND = AND|arr[j];
            
            ans =max(ans,j-i+1);
            
        }
        //ans = max(ans,j-i);
        return ans;
        
        
        
        
    }
};