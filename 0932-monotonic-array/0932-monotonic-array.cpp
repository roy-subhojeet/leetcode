class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = false;
        bool dec = false;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            if(nums[i] == nums[i+1])
            {
                continue;
            }
            else if(nums[i] > nums[i+1] && !inc && !dec) inc = true;
            else if(nums[i] < nums[i+1] && !inc && !dec)dec = true;
            if(inc && nums[i] < nums[i+1] && !dec) return false;
            if(dec && nums[i] > nums[i+1] && !inc) return false;
        }
        return true;
    }
};