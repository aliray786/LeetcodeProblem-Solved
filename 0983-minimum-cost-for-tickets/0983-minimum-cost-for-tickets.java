class Solution {
    int dp[];
       int minCostHelper(int n,int[]days,int[]costs,int index)
    {
        if(index>=n)
        {
            return 0;
        }
         //1day pass
         if(dp[index]!=-1) return dp[index];
         int oneday=costs[0]+minCostHelper(n,days,costs,index+1);
         
         int i=0;
         for( i=index;i<n && days[i]<days[index]+7;i++);
         //
         int sevenDay=costs[1]+minCostHelper( n,days,costs,i);
         for( i=index;i<n && days[i]<days[index]+30;i++);
         //
         int thirtyDay=costs[2]+minCostHelper( n,days,costs,i);
         return dp[index]=Math.min(oneday,Math.min(sevenDay,thirtyDay));
             
         
    }
    public int mincostTickets(int[] days, int[] costs) {
        dp=new int[days.length+2];
        for(int i=0;i<days.length;i++)
            dp[i]=-1;
        return minCostHelper(days.length,days,costs,0);
        
    }
}