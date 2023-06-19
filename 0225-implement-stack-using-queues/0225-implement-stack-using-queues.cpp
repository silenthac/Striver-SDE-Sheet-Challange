class MyStack {
public:
    queue<int>pq;
    MyStack() {
        
    }
    
    void push(int x) {
        int s = pq.size();
        pq.push(x);
        while(s--)
        {
            auto top = pq.front();
            pq.pop();
            pq.push(top);
            

            
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
        if(pq.size()==0)
            return true;
        else
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