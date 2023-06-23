






class Solution {
public:
    
    class TrieNode
{
    public:
    char c;
    vector<TrieNode*>vec;
    int childcount;
    bool is_end;
    
    
    TrieNode(char ch)
    {
        c= ch;
        for(int i=0;i<=25;i++)
        {
            vec.push_back(NULL);
        
        }
        childcount=0;
        is_end =false;
        
    }
};
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)
            return strs[0];
        
        TrieNode* p=  new TrieNode('0');
        TrieNode *head =p;
        
    string ans ="";
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].size()==0)
                return ans;
            p =head;
            
            addit(p,strs[i]);
        }
        
        string word = strs[0];
        for(int i=0;i<word.size();i++)
        {
           
            char ch = word[i];
            if(head->childcount==1)
            {
                ans+=ch;
                head = head->vec[ch-'a'];
            }
            else
            {
            break;
            }
            
            if(head->is_end==true)
            {
                break;
            }
        }
         
        
       
        return ans;
        
    }
    
    
    void addit(TrieNode* p,string s)
    {
        if(s.size()==0)
        {
            p->is_end =true;
            return;
        }
        
        int charind = s[0]-'a';
        
        if(p->vec[charind]!=NULL)
        {
            p = p->vec[charind];
        }
        else
        {
            p->vec[charind] = new TrieNode(s[0]);
                        p->childcount++;
            p = p->vec[charind];

        }
        
        addit(p,s.substr(1));
            
    }
    
    
    
};