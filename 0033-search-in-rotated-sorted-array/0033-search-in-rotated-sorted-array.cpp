class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left - (left - right)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
             // If the first half is sorted
            else if(nums[mid] >= nums[left])
            {
                // Check if target lies in the first half
                if(nums[mid] > target && nums[left] <= target)
                    right = mid - 1;
                // Otherwise target lies in the second half
                else
                    left = mid + 1;
            }
            // If the second half is sorted
            else
            {
                // Check if target lies in the second half
                if(nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                // Otherwise target lies in the first half
                    right = mid - 1;
            }
        }
        return -1;
    }
};