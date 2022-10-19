class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int temp = 0;
        priority_queue<int,vector<int>,greater<int> > q2;
        for(auto itr = prices.begin(); itr < prices.end(); itr++)
        {
            q2.push(*itr);
            if(itr != prices.end()-1)
            {
                temp = *(itr+1) - q2.top();
                if(q2.top() < *(itr+1) && profit < temp)
                    profit = temp;
            }
        }
        return profit;
        
    }
};