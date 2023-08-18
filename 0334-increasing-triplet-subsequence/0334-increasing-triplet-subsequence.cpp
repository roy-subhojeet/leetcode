class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int low = INT_MAX;
        int mid = INT_MAX;
        if(nums.size() < 3) return false;
        for(auto & num : nums)
        {
            if(num > mid) return true;
            else if(num < low) low = num;
            else if(num > low && num < mid) mid = num;
        }
        return false;
    }
};