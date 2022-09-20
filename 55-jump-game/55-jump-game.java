class Solution {
    int[]mem;
    int canReach(int[]nums,int pos)
    {
        if(pos==nums.length-1)
        {
            return 1;
        }
        if(mem[pos]!=-1) return mem[pos];
        int farthestJump=Math.min(nums.length-1,pos+nums[pos]);
        //if(farthestJump==nums.length-1) return 1;
        for(int i=pos+1;i<=farthestJump;i++)
        {
            if(canReach(nums,i)==1)
            {
                return mem[i]=1;
            }
        }
        return mem[pos]=0;
    }
    public boolean canJump(int[] nums) {
        mem=new int[nums.length+1];
        for(int i=0;i<nums.length+1;i++)mem[i]=-1;
        return canReach(nums,0)==1?true:false;
    }
}