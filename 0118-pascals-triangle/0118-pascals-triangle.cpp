class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>vec(n);
        vec[0].push_back(1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0||j==i)
                {
                   vec[i].push_back(1);
                }
                else
                {
                    vec[i].push_back(vec[i-1][j-1]+vec[i-1][j]);
                }
            }
        }
        return vec;
        
        
    }
};