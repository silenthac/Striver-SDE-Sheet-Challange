class Solution {
    public String mergeAlternately(String word1, String word2) {
        
        int s1 = word1.length();
        int s2 = word2.length();
        int i=0;
        int j=0;
        String ans = "";
        
        while(i<s1&&j<s2)
        {
            ans+=word1.charAt(i);
            ans+=word2.charAt(j);
            i++;
            j++;
            
        }
        
        while(i<s1)
        {
            ans+=word1.charAt(i);
            i++;
        }
        
        while(j<s2)
        {
            ans+=word2.charAt(j);
            j++;
        }
        
        return ans;
        
    }
}