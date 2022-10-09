class Solution {
    int n;
        vector<vector<vector<int>>>dp;
public:
    int getMaxProfit(vector<int>&prices,int i,int buy,int cap)
    {
        if(i>=n or cap==0) return 0;
        int profit=0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy)
        {
            profit=max(-prices[i]+getMaxProfit(prices,i+1,0,cap),getMaxProfit(prices,i+1,1,cap));
        }
        else
        {
            profit=max(prices[i]+getMaxProfit(prices,i+1,1,cap-1),getMaxProfit(prices,i+1,0,cap));
        
        }
        return dp[i][buy][cap]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
         n=prices.size();
        dp.resize(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return getMaxProfit(prices,0,1,k);
    }
};