class TrieNode{
    public:
    
    TrieNode* arr[2];
    
    TrieNode()
    {
        for(int i=0;i<2;i++)
        {
            arr[i] =NULL;
        }
    } 
    
    
    
    void insertit(int ele,TrieNode* root)
    {
        
        for(int i=31;i>=0;i--)
        {
            int bit = (ele>>i)&1;
            
            if(root->arr[bit]==NULL)
            {
                root->arr[bit] = new  TrieNode();
            }
            
            root = root->arr[bit];
            
        }
    }
    
     int findmax(TrieNode* root,int ele)
   {
       int maxSum=0;
       for(int i = 31;i>=0;i--)
       {
           int bit = (ele>>i)&1;
           int findbit = !bit;
           if(root->arr[findbit]!=NULL)
           {
               maxSum =maxSum|(1<<i);
               root = root->arr[findbit];
           }
           else
           {
               root =root->arr[bit];
           }
       }
       return maxSum;
   }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n =nums.size();
        vector<int>res(queries.size());
        sort(nums.begin(),nums.end());
        vector<vector<int>>newQueries(queries.size());
         TrieNode* root = new TrieNode();
        TrieNode* temp =root;
        for(int i=0;i<queries.size();i++)
        {
            newQueries[i].push_back(queries[i][1]);
            newQueries[i].push_back(queries[i][0]);
            newQueries[i].push_back(i);
            
        }
        
        sort(newQueries.begin(),newQueries.end());
        int j=0;
        int i=0;
        
        for (auto & it: newQueries) {
            
    while (i < n && nums[i] <= it[0]) {
        temp =root;
      temp->insertit(nums[i],temp);
      i++;
    }
            temp= root;
    if (i != 0) res[it[2]] = temp->findmax(temp,it[1]);
    else res[it[2]] = -1;
        }

            
        
        
           
        
        
        return res;
        
        
        
        
    }
};