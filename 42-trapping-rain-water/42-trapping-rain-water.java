class Solution {
    public int trap(int[] height) {
        int n=height.length;
        int leftMax=height[0];
        int rightMax=height[n-1];
        int ans=0;
        int i=1,j=n-2;
        while(i<=j)
        {
              rightMax=Math.max(rightMax,height[j]);
                leftMax=Math.max(leftMax,height[i]);

            if(leftMax<=rightMax)
            {
                ans+=leftMax-height[i]>0?leftMax-height[i]:0;
                i++;
            }
            else
            {
              ans+=rightMax-height[j]>0?rightMax-height[j]:0;
                j--;  
            }
        }
        return ans;
        
    }
}