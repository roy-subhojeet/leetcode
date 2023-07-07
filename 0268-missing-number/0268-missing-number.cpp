class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int missingNum = nums.size();
        int i = 0;
        for(auto &num:nums)
        {
            missingNum ^= i;
            missingNum ^= num;
            i++;
        }
        return missingNum;
        /* Formula Method
        int total = nums.size();
        total = 0.5*(total *(total + 1)); 
        for (auto &num: nums)
        {
            total -= num;
        }
        return total;  */
    }
};