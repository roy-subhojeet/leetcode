class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> maxI(n, INT_MIN); 
        vector<int> maxDiff(n, INT_MIN);


        maxI[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            maxI[i] = max(maxI[i - 1], nums[i]);
        }


        for (int j = 1; j < n; ++j) {
            maxDiff[j] = max(maxDiff[j - 1], maxI[j - 1] - nums[j]);
        }

        for (int k = 2; k < n; ++k) {
            if (maxDiff[k - 1] > INT_MIN) {
                ans = max(ans, (long long)maxDiff[k - 1] * nums[k]);
            }
        }

        return ans;
    }
};
