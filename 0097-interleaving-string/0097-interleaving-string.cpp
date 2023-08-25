class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
        {
            return false;
            
        }
        
        return solve(s1,s2,s3,s1.size()-1,s2.size()-1,s3.size()-1);
        
    }
    
     bool solve(string &s1,string &s2,string &s3,int index1,int index2,int index3)
     {
         if(index1<0&&index2<0&&index3<0)
         {
             return true;
         }
         
         if(index1>=0&&index2>=0&&index3>=0&&s1[index1]==s3[index3]&&s2[index2]==s3[index3])
         {
             return solve(s1,s2,s3,index1-1,index2,index3-1)||solve(s1,s2,s3,index1,index2-1,index3-1);
         }
         
         else if(index1>=0&&index3>=0&&s1[index1]==s3[index3])
         {
             return solve(s1,s2,s3,index1-1,index2,index3-1);
         }
         else if(index2>=0&&index3>=0&&s2[index2]==s3[index3])
         {
             return solve(s1,s2,s3,index1,index2-1,index3-1);
         }
         else
         {
             return false;
         }
     }
};