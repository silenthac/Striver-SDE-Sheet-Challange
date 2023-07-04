class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        ArrayList<Integer> list = new ArrayList<>();
        int s = flowerbed.length;
        
        if(s==1&&flowerbed[0]==0)
        {
            if(flowerbed[0]==0&&s<=1)
            {
                return true;
                
            }
            return false;
                
        }
        
       

        
        
        for(int i=0;i<s;i++)
        {
            if(flowerbed[i]==1)
            {
                continue;
            }
            else if(i==0)
            {
                if(s>1&&flowerbed[i]==0&&flowerbed[i+1]==0)
                {
                    flowerbed[i] =1;
                    n--;
                }
                
            }
            
            else if(s>1&&i==s-1)
            {
                
                if(flowerbed[i]==0&&flowerbed[i-1]==0)
                {
                    flowerbed[i] =1;
                    n--;
                }
                
            }
           
            else if(flowerbed[i-1]==0&&flowerbed[i+1]==0)
            {
                flowerbed[i] = 1;
                n--;
            }
            
            
        }
        
        if(n<=0)
        {
            return true;
        }
        return false;
        
        
        
    }
}