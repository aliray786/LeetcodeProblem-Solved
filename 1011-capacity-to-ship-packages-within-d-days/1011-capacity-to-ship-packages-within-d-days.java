class Solution {
    boolean isPos(int[] weights, int days,int max)
    {
        int day=1,sum=0;
        for(int i=0;i<weights.length;i++)
        {
            sum+=weights[i];
            if(sum>max)
            {
                sum=weights[i];
                day++;
            }
            if(day>days)
                return false;
        }
return true;
    }
    public int shipWithinDays(int[] weights, int days) {
        int ans=-1;
        int len=weights.length;
        int start=0, end=0,mid;
        for(int i=0;i<len;i++)
        {
            start=Math.max(weights[i],start);
            end+=weights[i];
        }
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
        return ans;
        
    }
}