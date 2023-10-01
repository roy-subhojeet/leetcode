class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        vector<int> maxRight(n, INT_MIN);
        for (int i = n - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], nums[i + 1]);
        }

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                if (nums[i] > nums[j]) {
                    ans = max<long long int>(ans, (long long)(nums[i] - nums[j]) * maxRight[j]);
                }
            }
        }

        return ans;
    }
};