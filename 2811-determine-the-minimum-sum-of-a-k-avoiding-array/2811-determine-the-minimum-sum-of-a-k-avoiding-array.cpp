class Solution {
public:
    int minimumSum(int n, int k) {

        std::vector<int> result;
        int i = 1;
        int sum = 0;
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
                sum += i;
            }
            i++;
        }
    
        return sum;
    }
};