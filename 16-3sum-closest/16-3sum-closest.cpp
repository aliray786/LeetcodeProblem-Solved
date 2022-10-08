class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int closetSum=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int first=0;first<n-2;first++)
        {
            if(first!=0 and nums[first]==nums[first-1])continue;
            int second=first+1,third=n-1;
            while(second<third)
            {
                int curSum=nums[first]+nums[second]+nums[third];
                if(curSum==target) return target;
                if(abs(curSum-target)<abs(closetSum-target))
                {
                    closetSum=curSum;
                }
                if(curSum>target)
                    third--;
                else 
                {
                    second++;
                }
            }
        }
        return closetSum;
    }
};