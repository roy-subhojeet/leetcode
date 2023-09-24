class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long global_max_sum = 0;

        for (int i = 0; i < n; ++i) {
            long long current_sum = maxHeights[i];
            int left_max = maxHeights[i];
            for (int j = i - 1; j >= 0; --j) {
                left_max = min(left_max, maxHeights[j]);
                current_sum += left_max;
            }
            
            int right_max = maxHeights[i];
            for (int j = i + 1; j < n; ++j) {
                right_max = min(right_max, maxHeights[j]);
                current_sum += right_max;
            }

            global_max_sum = max(global_max_sum, current_sum);
        }
        return global_max_sum;
    }
};
