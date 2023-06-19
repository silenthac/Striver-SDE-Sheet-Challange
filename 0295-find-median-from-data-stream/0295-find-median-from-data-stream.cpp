//As in  this question i have to findmid element we can use  simple array also but we have to sort that again and again to  find middle element to overcome this problem heaps  comes into picture as it store elemt in  some prority based and that priority  is based on increaisng and decreasing  order we will use two things min heap and max heap and we will try to put equal element in  both and then just we have to apply conditions  

class MedianFinder {
public:
    
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    int  count;
    
    MedianFinder() {
         count=0;
        
        
        
    }
    
    void addNum(int num) {
        count++;
         if(left.empty()||left.top()>num)
         {
             left.push(num);
         }
        else
        {
            right.push(num);
        }
        
        if(left.size()>right.size()+1)
        {
            right.push(left.top());
            left.pop();
        }
        
         if(right.size()>left.size()+1)
        {
            left.push(right.top());
            right.pop();
        }
    
    }
        
        
        
        
       
      
        
        
    
    
    double findMedian() {
        
        if(left.size()==right.size())
        {
            if(left.size()==0)
            {
                return 0.0;
            }
            else
            {
                return (left.top()+right.top())/2.0;
            }
        }
        else
        {
            if(left.size()>right.size())
            {
                return left.top();
            }
            else
            {
                return right.top();
            }
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */