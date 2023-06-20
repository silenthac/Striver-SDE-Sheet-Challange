class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n =nums.size();   
       vector<long long >prefixSum(nums.size());
        prefixSum[0] = nums[0];
        vector<int>vec(nums.size(),-1);
        for(int i=1;i<nums.size();i++)
        {
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if((i-k)>=0&&(i+k)<n)
            {
                int left =i-k;
                int right = i+k;
                long long dia = (2*k)+1;
                long long sum = prefixSum[right];
                if(left>0)
                {
                    sum = sum-prefixSum[left-1];
                }
                vec[i] = sum/dia;
                
                
            }
        }
        
   
        return vec;
        
        
    }
};

// class Solution {
// public:
//     vector<int> getAverages(vector<int>& nums, int k) {
//          vector<int> result(nums.size(),-1);
//         vector<long long> c(nums.size());
//         c[0]=nums[0];
//         for(int i=1;i<nums.size();i++)
//         {
//             c[i]=c[i-1]+nums[i];
//         }
//         for(int i=0;i<nums.size();i++)
//         {
//             if(i-k>=0 && i+k<nums.size())
//             {
//                 int b=i+k;
//                 int a=i-k;
//                 long long n=(2*k)+1;
//                 long long val=c[b];
//                 if(a>0)
//                     val-=c[a-1];
//                 result[i]=val/n;
//             }
//         }
//         return result;
//     }
// };