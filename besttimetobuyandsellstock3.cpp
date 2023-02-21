class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price1=INT_MAX;
        int profit1=0;
        int min_price2=INT_MAX;
        int profit2=0;
        for (int i=0; i<prices.size();i++)
        {
            min_price1=min(prices[i],min_price1);
            profit1=max(profit1,prices[i]-min_price1);
            min_price2=min(min_price2,prices[i]-profit1);
            profit2=max(profit2,prices[i]-min_price2);
        }
        return profit2;
    }
};
