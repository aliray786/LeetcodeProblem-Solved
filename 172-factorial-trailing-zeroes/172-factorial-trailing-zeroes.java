class Solution {
    public int trailingZeroes(int n) {
        if(n<5) return 0;
        int count=0;
        for(int i=5;n/i>0;i=i*5)
        {
            count=count+n/i;
        }
        return count;
        
    }
}