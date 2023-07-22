class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minProfit = 65535;
        int maxProfit = 0;
        for(auto &p : prices)
        {
            minProfit = min(minProfit, p);
            maxProfit = max(maxProfit, p - minProfit);
        }
        return maxProfit;

        /* First Logic that came to mind
        int i = 0;
        int maxProfit = 0;
        for(auto & price: prices)
        {
            int k = i;
            while(k!=0)
            {
                --k;
                if(prices[k] < price)
                {
                    maxProfit = max(maxProfit, price - prices[k]);
                }
            }
            ++i;
        }
        return maxProfit;
        */
    }
};