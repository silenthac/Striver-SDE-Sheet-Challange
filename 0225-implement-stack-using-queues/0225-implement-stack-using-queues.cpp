class MyStack {
public:
    queue<int>pq1;
    queue<int>pq2;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!pq1.empty())
        {
            pq2.push(pq1.front());
            pq1.pop();
        }
        pq1.push(x);
        while(!pq2.empty())
        {
            pq1.push(pq2.front());
            pq2.pop();
        }
        
        
    }
    
    int pop() {
        int ele =  pq1.front();
        pq1.pop();
        return ele;
        
        
    }
    
    int top() {
        return pq1.front();
        
        
    }
    
    bool empty() {
        
        if(pq1.size()==0)
            return true;
        return false;
        
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