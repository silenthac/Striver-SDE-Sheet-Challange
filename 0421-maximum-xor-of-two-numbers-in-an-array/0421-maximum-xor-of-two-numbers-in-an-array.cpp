// class TrieNode{
//     public:
    
//     TrieNode* arr[2];
    
//     TrieNode()
//     {
//         for(int i=0;i<2;i++)
//         {
//             arr[i] =NULL;
//         }
//     } 
    
    
    
//     void insert(int ele,TrieNode* root)
//     {
        
//         for(int i=31;i>=0;i--)
//         {
//             int bit = (ele>>i)&1;
            
//             if(root->arr[bit]==NULL)
//             {
//                 root->arr[bit] = new  TrieNode();
//             }
            
//             root = root->arr[bit];
            
//         }
//     }
    
    
//    int findmax(TrieNode* root,int ele)
//    {
//        int maxSum=0;
//        for(int i = 31;i>=0;i--)
//        {
//            int bit = (ele>>i)&1;
//            int findbit = !bit;
//            if(root->arr[findbit]!=NULL)
//            {
//                maxSum =maxSum|(1<<i);
//                root = root->arr[findbit];
//            }
//            else
//            {
//                root =root->arr[bit];
//            }
//        }
//        return maxSum;
//    }
// };







class Solution {
public:
    
  
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
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        TrieNode* temp =root;
        for(int i=0;i<nums.size();i++)
        {
             temp =root;
            temp->insertit(nums[i],temp);
        }
        
        temp = root;
        int res =0;
        
        for(int i=0;i<nums.size();i++)
        {
            TrieNode* temp =root;
            
           res = max(res,temp->findmax(temp,nums[i]));
        }
        
        return res;
        
        
    }
};