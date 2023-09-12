class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        if(bank.empty()) return 0;
        
        
        int prevCount = 0;
        int ans = 0;

        for(auto & s: bank)
        {
            int currentCount = 0;
            for(auto & c : s)
            {
                if(c == '1') ++currentCount;
            }
            ans += currentCount*prevCount;
            if(currentCount != 0) prevCount = currentCount;
        }
        return ans;
    }
};