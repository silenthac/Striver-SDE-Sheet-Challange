class LRUCache {
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        
        Node(int k,int v)
        {
            key = k;
            val =v;
            
        }
    };
    
  
    
public:
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*>mp;
    int cap;
    
    void deleteNode(Node*delNode)
    {
        Node*delprev =delNode->prev;
        Node* delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        
        
    }
    
    void addNode(Node* addNode)
    {
        Node* temp = head->next;
        addNode->prev =head;
        addNode->next = temp;
        temp->prev = addNode;
        head->next = addNode;
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next =tail;
        tail->prev= head;   
        
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        else
        {
        Node*add = mp[key];
        int val = add->val;
            mp.erase(key);
            deleteNode(add);
        
         addNode(new Node(key,val));
        mp[key] = head->next;
        return val;
        }
    }
    
    void put(int key, int value) {
       
         if(mp.find(key)!=mp.end())
        {
            Node*add = mp[key];
            mp.erase(key);
            deleteNode(add);  
            addNode(new Node(key,value));
        mp[key] = head->next;
        }
        else if(cap==mp.size())
        {
            Node* delNode = tail->prev;
            mp.erase(delNode->key);
            deleteNode(delNode);
            addNode(new Node(key,value));
          mp[key] = head->next;
            
            
        }
        
        else{
       addNode(new Node(key,value));
        mp[key] = head->next;
    }
       
        
        
    }
        

        
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */