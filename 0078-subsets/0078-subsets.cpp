#include <vector>
#include <string>
#include <cmath>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> output;
        int n = nums.size();
        
        for (int i = std::pow(2, n); i < std::pow(2, n + 1); ++i) {
            // Generate bitmask, from 0..00 to 1..11
            std::string bitmask = std::bitset<32>(i).to_string().substr(32 - n);
            
            // Append subset corresponding to that bitmask
            std::vector<int> curr;
            for (int j = 0; j < n; ++j) {
                if (bitmask[j] == '1') curr.push_back(nums[j]);
            }
            output.push_back(curr);
        }
        return output;
    }
};
