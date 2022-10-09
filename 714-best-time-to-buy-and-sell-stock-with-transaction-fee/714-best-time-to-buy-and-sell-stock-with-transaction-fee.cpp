class Solution {
     int n;
   vector<vector<int>>dp; 
    int fee;
public:
    int getMaxProfit(vector<int>&prices,int i,int buy)
    {
        if(i==n) return 0;
        int profit=0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy)
        {
            profit=max(-prices[i]+getMaxProfit(prices,i+1,0),getMaxProfit(prices,i+1,1));
        }
        else
        {
            profit=max(prices[i]-fee+getMaxProfit(prices,i+1,1),getMaxProfit(prices,i+1,0));
        
        }
        return dp[i][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
         n=prices.size();
        this->fee=fee;
        dp.resize(n,vector<int>(2,-1));
                return getMaxProfit(prices,0,1);

    }
};