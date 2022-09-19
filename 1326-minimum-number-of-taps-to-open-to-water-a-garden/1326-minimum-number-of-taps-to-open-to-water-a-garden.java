class Solution {
    public int minTaps(int n, int[] ranges) {
        int tap=0;
        int max=0,min=0;
        while(max<n)
        {
            for(int i=0;i<ranges.length;i++)
            {
                if(i+ranges[i]>max && i-ranges[i]<=min)
                {
                    max=i+ranges[i];
                }
            }
           tap++;
           if(min==max) return -1;
            min=max;
        }
        return tap;
    }
}