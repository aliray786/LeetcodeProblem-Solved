class Solution {
    public int maxSubArray(int[] nums) {
        int maxEndingHere=0;
        int maxSoFar=Integer.MIN_VALUE;
        
        for(int num:nums)
        {
            maxEndingHere=Math.max(num,maxEndingHere+num);
            maxSoFar=Math.max(maxSoFar,maxEndingHere);
        }
        return maxSoFar;
        
    }
}