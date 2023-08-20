class Solution {
public:
    int minimumSum(int n, int k) {

        std::vector<int> result;
        int i = 1;
        while (result.size() < n) {
            bool shouldAdd = true;
            for (int num : result) {
                if (i + num == k) {
                    shouldAdd = false;
                    break;
                }
            }
            if (shouldAdd) {
                result.push_back(i);
            }
            i++;
        }
        int sum = 0;
        for (int num : result) {
            sum += num;
        }
        return sum;
    }
};