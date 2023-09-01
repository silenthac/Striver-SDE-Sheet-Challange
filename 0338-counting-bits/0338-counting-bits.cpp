class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int count=0;
            int j=i;
            while(j!=0)
            {
                int check= j&1;
                if(check!=0)
                {
                    count++;
                }
                j= j>>1;
            }
            ans.push_back(count);
        }
        return ans;
        
    }
};