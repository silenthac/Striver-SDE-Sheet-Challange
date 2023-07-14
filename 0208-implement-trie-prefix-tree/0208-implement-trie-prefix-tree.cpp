class TrieNode
{
    public:
    char child;
    bool isterminal;
    //vector<TrieNode*>children(26,NULL);
    TrieNode* children[26];
    
    TrieNode(char ch)
    {
        child =ch;
        isterminal =false;
        for(int i=0;i<26;i++)
        {
            children[i] =NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root =new TrieNode('/');
    Trie() {
        
        
        
        
    }
    
    void insert(string word) {
        insertUtil(root,word);
        
    }
    
    void insertUtil(TrieNode* root,string word)
    {
        if(word.size()==0)
        {
            root->isterminal =true;
            return;
        }
        
        TrieNode* temp =root;
        int index = word[0]-'a';
        if(root->children[index]==NULL)
        {
            root->children[index] = new TrieNode(word[0]);
            
            
        }
        temp = root->children[index];
        
        insertUtil(temp,word.substr(1));
        
    }
    
    bool search(string word) {
        
    return searchUtil(root,word);
        
    }
    
    bool searchUtil(TrieNode* root,string word)
    {
        if(word.size()==0)
        {
            if(root->isterminal ==true)
                return true;
            else
                return false;
        }
        
        int index = word[0]-'a';
        if(root->children[index]==NULL)
            return false;
        
        return searchUtil(root->children[index],word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(root,prefix);
        
        
    }
    
    bool startsWithUtil(TrieNode* root,string prefix)
    {
        if(prefix.size()==0)
            return true;
        
        int index = prefix[0]-'a';
        if(root->children[index]==NULL)
        {
            return false;
        }
        
        return startsWithUtil(root->children[index],prefix.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */