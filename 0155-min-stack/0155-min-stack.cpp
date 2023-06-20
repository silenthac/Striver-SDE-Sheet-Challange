class MinStack {
public:
    stack<long long>stk;
    int miniele;
    MinStack() {
        
        
        
    }
    
    void push(int ele) {
        
        if(stk.empty())
        {
            stk.push(ele);
            miniele = ele;
        }
        
        else
        {
            if(ele>=miniele)
            {
                stk.push(ele);
            }
            else if(ele<miniele)
            {
                //we will push false value which will act as flag 
                stk.push(1ll*2*ele-miniele);
                miniele = ele;
                
            }
        }
        
        
        
    }
    
    void pop() {
        if(stk.empty())
            return;
        
        else
        {
            if(stk.top()>=miniele)
            {
                stk.pop();
            }
            
            else if(stk.top()<miniele)
            {
                miniele =  1ll*2*miniele-stk.top();
                stk.pop();
            }
            
        }
        
    }
    
    int top() {
        if(stk.empty())
            return -1;
        if(stk.top()>=miniele)
        {
            return stk.top();
        }
        else if(stk.top()<miniele)
        {
            return miniele;
        }
        return -1;
        
        
    }
    
    int getMin() {
        
       if(stk.empty())
           return -1;
        return miniele;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */