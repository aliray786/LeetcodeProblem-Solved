class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int bd=0,sd=0,profit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>=prices[i-1])
            {
                         profit+=(prices[i]-prices[i-1]);

            }
           
        }
        return profit;
    }
};