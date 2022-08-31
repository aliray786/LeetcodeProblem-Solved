class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int size=gas.length;
        int petrol=0, start=0,end=0;
        for(int i=0;i<size;i++)
        {
            petrol+=gas[i]-cost[i];
        }
        if(petrol<0) return -1;
        petrol=0;
        for(;end<size;end++)
        {
            petrol+=(gas[end]-cost[end]);
            if(petrol<0)
            {
                start=end+1;
                petrol=0;
            }
        }
        return start;
    }
}