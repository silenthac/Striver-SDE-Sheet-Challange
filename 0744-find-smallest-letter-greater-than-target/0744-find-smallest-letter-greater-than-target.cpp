class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
       
      int x =  upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        return x<=letters.size()-1?letters[x]:letters[0];
        
        
       
        
        
        
    }
};