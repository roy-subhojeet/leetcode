class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int a = nums[nums.size()-1];
        return (k*(2*a + (k-1)*1))/2;
    }
};