class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int profit =0;
        int mini = prices[0];
        int maxi = prices[0];
        for(int i=1;i<n;i++)
        {
            mini = min(mini,prices[i]);
            maxi = max(mini,prices[i]);
            profit = max(profit,(maxi-mini));
        }
        
        
        return profit;
        
    }
};