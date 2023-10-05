#include <vector>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {

        int count1 = 0;
        int count2 = 0;

        int candidate1 = 0; 
        int candidate2 = 0; 
        bool candidate1Exists = false;
        bool candidate2Exists = false; 

        for (int n : nums) {
            if (candidate1Exists && candidate1 == n) {
                count1++;
            } else if (candidate2Exists && candidate2 == n) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = n;
                count1++;
                candidate1Exists = true;
            } else if (count2 == 0) {
                candidate2 = n;
                count2++;
                candidate2Exists = true;
            } else {
                count1--;
                count2--;
            }
        }

        std::vector<int> result;

        count1 = 0;
        count2 = 0;

        for (int n : nums) {
            if (candidate1Exists && n == candidate1) count1++;
            if (candidate2Exists && n == candidate2) count2++;
        }

        int n = nums.size();
        if (count1 > n/3) result.push_back(candidate1);
        if (count2 > n/3) result.push_back(candidate2);

        return result;
    }
};
