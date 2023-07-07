class Solution {
public:
    int maxConsecutiveAnswers(string answerkey, int k) {
        return max(solve(answerkey,k,'T'),solve(answerkey,k,'F'));
        
        
    }
    
    
    int solve(string nums,int k,char c)
    {
         int n =nums.size();
        int i=0;
        int  j=0;
        int ans=0;
        while(j<n)
        {
            if(nums[j]==c)
            {
                j++;
            }
            else
            {
                if(k>0)
                {
                    j++;
                    k--;
                    
                }
                else
                {
                    ans =max(ans,j-i);
                    if(nums[i]==c)
                    {
                        i++;
                    }
                    else
                    {
                        k++;
                        i++;
                    }
                }
            }
            
        }
        ans = max(ans,j-i);
        return ans;
        
    }
    
};