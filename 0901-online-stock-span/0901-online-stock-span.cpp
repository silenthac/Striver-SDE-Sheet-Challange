class StockSpanner {
public:
    stack<pair<int,int>>stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        if(stk.empty()||stk.top().first>price)
        {
            stk.push({price,1});
            return 1;
        }
        else if(stk.top().first<=price)
        {
            int count=1;
            while(!stk.empty()&&stk.top().first<=price)
            {
                count+=stk.top().second;
                stk.pop();
            }
            stk.push({price,count});
            return count;
        }
        return -1;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */