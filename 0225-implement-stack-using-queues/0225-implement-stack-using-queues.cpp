class MyStack {
public:
    queue<int>pq;
    MyStack() {
        
    }
    
    void push(int x) {
        pq.push(x);
        int size = pq.size();
        size--;
        while(size--)
        {
            pq.push(pq.front());
            pq.pop();
        }
        
    }
    
    int pop() {
        
        int x = pq.front();
        pq.pop();
        return x;
        
        
    }
    
    int top() {
        
        return pq.front();
        
    }
    
    bool empty() {
        
        return pq.empty();
        
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