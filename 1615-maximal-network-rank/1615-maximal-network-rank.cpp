// first of all we will find the degree if each and every node as per the question


class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans=0;
        vector<int>indegree(n,0);
        vector<vector<bool>>matrix(n,vector<bool>(n,false));
        for(auto it:roads)
        {
            matrix[it[0]][it[1]]=true;
            matrix[it[1]][it[0]]=true;
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int rank1 = indegree[i];
                int rank2 = indegree[j];
                int total = rank1+rank2;
                
                if(matrix[i][j]==true)
                {
                    total = total-1;
                }
                
                ans = max(ans,total);
                }
        }
        return ans;
        
        
        
        
        
        
        
    }
};