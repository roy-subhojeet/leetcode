class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = nums.size();
        total = 0.5*(total *(total + 1));
        for (auto &num: nums)
        {
            total -= num;
        }
        return total;
    }
};