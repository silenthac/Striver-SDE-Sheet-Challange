class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans ="";
        while(columnNumber>0){
            columnNumber--;
        // if(columnNumber<=26)
        // {
        //     ans+=char('A'+(columnNumber));
        //     break;
        // }
        // else
        
            int div = columnNumber%26;
            ans+=char('A'+(div));
            columnNumber = columnNumber/26;
            
        
    }
        
      
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};