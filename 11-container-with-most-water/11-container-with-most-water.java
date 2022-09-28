class Solution {
    public int maxArea(int[] height) {
        int mostWater=0;
        int size=height.length;
         int left=0,right=size-1;
        while(left<right)
        {
            if(height[left]>height[right])
            {
                mostWater=Math.max(mostWater,((right-left)*height[right]));
                right--;

            }
            else
            {
                  mostWater=Math.max(mostWater,((right-left)*height[left]));
                left++;

            }
        }
        return mostWater;
    }
}