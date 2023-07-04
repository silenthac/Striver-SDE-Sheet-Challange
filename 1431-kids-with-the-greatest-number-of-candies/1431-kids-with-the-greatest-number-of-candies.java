class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        ArrayList<Boolean>list = new ArrayList();
        int maxi =0;
        
        for(int i=0;i<candies.length;i++)
        {
            maxi = Math.max(maxi,candies[i]);
            
        }
        
        for(int i=0;i<candies.length;i++)
        {
            if(candies[i]+extraCandies>=maxi)
            {
                list.add(true);
            }
            else
            {
                list.add(false);
            }
        }
        return list;
        
    }
}