class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxVal = INT_MIN;
        int minVal = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] <= prices[i-1]) 
            {
                maxProfit += 0;
                minVal = prices[i];
            }
            else
            {
                maxProfit += prices[i] - prices[i-1];
            }
        }
        return maxProfit;
    }
};