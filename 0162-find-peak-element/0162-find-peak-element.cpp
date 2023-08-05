class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() -1;
        while(left < right)
        {
            int mid = left - (left - right)/2;
            if(nums[mid+1] < nums[mid])
                right = mid;
            else
                left = mid + 1;
        }
        return right;
        
    }
};