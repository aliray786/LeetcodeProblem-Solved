class Solution {
     boolean isPos(int[] weights, int days,int max)
    {
         long hour=0;
         for(int i=0;i<weights.length;i++)
         {
             hour+=weights[i]/max;
             hour+=(weights[i]%max!=0?1:0);
             if(hour>days) return false;
         }
         return hour<=days;
     }
    
    public int minEatingSpeed(int[] weights, int days) {
        int ans=-1;
        int len=weights.length;
        int start=0, end=0,mid;
        for(int i=0;i<len;i++)
        {
            end=Math.max(weights[i],end);
        }
        start=1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(isPos(weights,days,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return start;
        
    }
    
}