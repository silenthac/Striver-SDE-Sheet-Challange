class Solution {
public:
    void sortColors(vector<int>& arr) {
        int left=0;
        int right =arr.size()-1;
        int mid=0;
        while(mid<=right)
        {
           if(arr[mid]==2)
           {
               swap(arr[mid],arr[right]);
               right--;
           }
            
            else if(arr[mid]==0)
            {
                swap(arr[left],arr[mid]);
                mid++;
                left++;
            }
            else
            {
                mid++;
            }
            
            
            
        }
        
        
        
    }
};