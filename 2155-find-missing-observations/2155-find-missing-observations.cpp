class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        int sum = 0;
        for(auto &i : rolls)
        {
            sum += i;
        }
        cout << sum << endl;
        cout << rolls.size();

        int totalSize = rolls.size() + n;

        int missingSum = mean*totalSize - sum;
        if(missingSum < 0) return {};
        int missingSumRemainder = missingSum%n;

        vector<int> ans;

        if(missingSum > 6*n || missingSum < n) return ans;

        cout << missingSum << endl;

        int s = 0;
        while(s != missingSum)
        {
            int x = missingSum/n;
            if(missingSumRemainder > 0)
            {
                x = x + 1;
                --missingSumRemainder;
            }
            s += x;
            ans.push_back(x);
        }
        return ans;
        
    }
};