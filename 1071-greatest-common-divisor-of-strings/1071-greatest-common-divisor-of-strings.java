class Solution {
    
    public boolean isPossible(String s,String str1,String str2)
    {
         
           
       
        
        int s1 = str1.length();
        int s2 = str2.length();
        boolean ans = false;
        int tsize = s.length();
        if(s1%tsize==0&&s2%tsize==0)
        {
            int count1 = s1/tsize;
            int count2 =s2/tsize;
         
            
            String temps1 = "";
            String temps2 = "";
            while(count1>0)
            {
                temps1+=s;
                count1--;
            }
           // System.out.println(temps1);
            
            while(count2>0)
            {
                temps2+=s;
                count2--;
            }
            
            
            
            if(temps1.equals(str1)&&temps2.equals(str2))
            {
               ans =true; 
            }
        }
         
        
        return ans;
        
    }
    
    
    public String gcdOfStrings(String str1, String str2) {
       int s1;
        int s2;
        if(str1.length()<=str2.length())
        {
            
            s1 = str1.length();
            s2 = str2.length();
            
        }
        else
        {
            
            s2 = str1.length();
            s1 = str2.length();
            String temp = str1;
            str1 =str2;
            str2  = temp;
        }
       // System.out.println(str1+" "+str2);
        
       
        
        int i  = s1;
        String ans = "";
        while(i>=1)
        {
            String s = str1.substring(0,i);
            
            if(isPossible(s,str1,str2))
            {
                ans =s;
                break;
            }
            i--;
        }
        return ans;
        
        
      
        
        
        
    }
}