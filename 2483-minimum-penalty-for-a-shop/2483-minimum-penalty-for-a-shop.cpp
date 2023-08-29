class Solution {
public:
    int bestClosingTime(string arr) {
        int n = arr.size();
        vector<int>left(n+1,0);
        vector<int>right(n+1,0);
        
        left[0]=0;
        for(int i=1;i<left.size();i++)
        {
            if(arr[i-1]=='N')
            {
                left[i]=  left[i-1]+1;
            }
            else
            {
                left[i]=  left[i-1];
            }
        }
        
         right[right.size()-1]=0;
        for(int i=right.size()-2;i>=0;i--)
        {
            if(arr[i]=='Y')
            {
                right[i] = right[i+1]+1;
            }
            else
            {
                right[i] = right[i+1];
            }
        }
        // for(int i=0;i<right.size();i++)
        // {
        //     cout<<right[i]<<" ";
        // }
        
        int index=-1;
        int ans=INT_MAX;
        
        for(int i=0;i<right.size();i++)
        {
            if(left[i]+right[i]<ans)
            {
                ans  =left[i]+right[i];
                index =i;
            }
        }
        return index;
        
       
        
    }
};