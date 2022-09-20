class Solution {
   
    public int jump(int[] nums) {
       int jump=0,curEnd=0,farthestJump=0;
        for(int i=0;i<nums.length-1;i++)
        {
            farthestJump=Math.max(farthestJump,i+nums[i]);
            if(i==curEnd)
            {
                jump++;
                curEnd=farthestJump;
            }
        }
        return jump;
        
    }
}