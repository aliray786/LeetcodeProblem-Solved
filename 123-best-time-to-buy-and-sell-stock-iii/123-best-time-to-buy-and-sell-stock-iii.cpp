class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        if(n==0)
            return 0;
        vector<int>left(n),right(n);
        int leftmin=p[0];
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],p[i]-leftmin);
            leftmin=min(leftmin,p[i]);
        }
        int rightmax=p[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],rightmax-p[i]);
            rightmax=max(rightmax,p[i]);
        }
        int profit=right[0];
        for(int i=1;i<n;i++)
        {
            profit=max(profit,left[i-1]+right[i]);
            
        }
        return profit;
        
    }
};