class Solution {
public:
    //in this question we will apply binary search  we have index just try to put the mid value at that index and one less on both sides and same to both sides 
    
//     bool isGood(int index,int n,long long mid,int maxSum)
//     {
//         int tempmid =mid;
//         int addit = mid-1;
//         int tempind = index-1;
//         while(tempind>=0)
//         {
//             if(addit==0)
//             {
//                 addit=1;
//             }
//             mid = mid+addit;
//             addit--;
//             tempind--;
//         }
        
//         addit = tempmid-1;
//         tempind = index+1;
//         while(tempind<n)
//         {
//             if(addit==0)
//             {
//                 addit=1;
//             }
//             mid = mid+addit;
//             addit--;
//             tempind++;
//         }
        
//         if(mid<=maxSum)
//         {
//             return true;
//         }
//         else
//             return false;
//     }
    
    long long calc(long long val)
    {
        return ((val)*(val+1))/2;
    }
    long long solve(int emptyplaces,int val)
    {
        long long sum=0;
        if(emptyplaces>=val)
        {
            sum = sum+calc(val);
            sum+=emptyplaces-val;
        }
        else
        {
            sum = sum+calc(val);
            sum =sum-calc(val-emptyplaces);
        }
        
        return sum;
        
        
    }
    int maxValue(int n, int index, int maxSum) {
        int leftcount = index;
        int rightcount = n-index-1;
        
        int low=1;
        int high = maxSum;
        int ans;
        while(low<=high)
        {
            long long  mid = low+(high-low)/2;
            long long findleftSum = solve(leftcount,mid-1);
            long long findrightSum = solve(rightcount,mid-1);
            long long totalsum = mid+ findleftSum+findrightSum;
            if(totalsum<=maxSum)
            {
                ans =mid;
                low =mid+1;
            }
            else
            {
                high =mid-1;
            }
            
            
           
        }
        return ans;
        
        
        
        
       
        
    }
};