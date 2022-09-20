class Solution {
    int [] dp;
    int minJump(int[]nums,int pos)
    {
        if(pos>=nums.length-1) return 0;
        if(dp[pos]!=-1) return dp[pos];
        int minJumps=10001;
        for(int i=1;i<=nums[pos];i++)
        {
            minJumps=Math.min(minJumps,1+minJump(nums,pos+i));
        }
        return dp[pos]=minJumps;
    }
    public int jump(int[] nums) {
        dp=new int[nums.length+1];
        for(int i=0;i<nums.length;i++)dp[i]=-1;
        return minJump(nums,0);
    }
}