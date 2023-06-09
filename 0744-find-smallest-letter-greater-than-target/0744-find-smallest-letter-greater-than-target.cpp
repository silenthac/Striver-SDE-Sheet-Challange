class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int diff = INT_MAX;
        int targetIndex = target-'a';
        for(int i=0;i<letters.size();i++)
        {
            int ind = letters[i]-'a';
           int currentDiff = ind-targetIndex;
            
            if(currentDiff>0&&currentDiff<diff)
            {
                diff = currentDiff;
            }
            
        }
        if(diff==INT_MAX)
        {
            return letters[0];
        }
        return (targetIndex+diff+'a');
       
        
        
        
    }
};