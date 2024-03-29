class Solution {
    public int firstMissingPositive(int[] nums) {
        int size=nums.length;
        for(int i=0;i<size;i++)
        {
            while(nums[i]>0 && nums[i]<=size && nums[i]!=nums[nums[i]-1])
            {
                int temp=nums[nums[i]-1];
                nums[nums[i]-1]=nums[i];
                nums[i]=temp;
            }
        }
        for(int i=0;i<size;i++)           
        {
            if(nums[i]!=i+1)
            {
                return i+1;
            }
        }
        return size+1;
        
    }
}