class Solution {
public:
    double myPow(double x, int n) {
        
        int pow = abs(n);
        
        double ans=  solve(x,pow);
        if(n<0)
        {
            return 1/ans;
        }
        return ans;
            
    }
    
    double solve(double x,int n)
    {
         if(n==0)
            return 1;
        
        double temp = solve(x,n/2);
        temp = temp*temp;
        if(n%2==0)
        {
            return temp;
        }
        else
        {
            return x*temp;
        }
    }
};