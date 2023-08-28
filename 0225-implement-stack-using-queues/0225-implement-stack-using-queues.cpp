class MyStack {
public:
    queue<int>pq1;
        queue<int>pq2;
    MyStack() {
        
        
    }
    
    void push(int x) {
        pq1.push(x);
        
    }
    
    int pop() {
        
        int ans;
        
        while(!pq1.empty())
        {
            if(pq1.size()==1)
            {
                ans = pq1.front();
                pq1.pop();
            }
            else
            {
                pq2.push(pq1.front());
                pq1.pop();
            }
        }
        
        while(!pq2.empty())
        {
            pq1.push(pq2.front());
            pq2.pop();
        }
        
        return ans;
        

        
    }
    
    int top() {
        
        int ans;
        
         while(!pq1.empty())
        {
            if(pq1.size()==1)
            {
                ans = pq1.front();
                pq2.push(pq1.front());
                pq1.pop();
            }
            else
            {
                pq2.push(pq1.front());
                pq1.pop();
            }
        }
        
        while(!pq2.empty())
        {
            pq1.push(pq2.front());
            pq2.pop();
        }
        
        return ans;
        
        
        
    }
    
    bool empty() {
        
        return pq1.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */