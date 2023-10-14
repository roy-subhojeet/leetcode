#include <vector>
#include <string>
#include <cmath>

#include <vector>
#include <iostream>

class Solution {
public:

    void backtrack(int first, std::vector<int>& curr, std::vector<int>& nums, int n, int k , std::vector<std::vector<int>>& output) {
        // if the combination is done
        if (curr.size() == k) {
            output.push_back(curr);
            return;
        }
        for (int i = first; i < n; ++i) {
            // add i into the current combination
            curr.push_back(nums[i]);
            // use next integers to complete the combination
            backtrack(i + 1, curr, nums, n, k, output);
            // backtrack
            curr.pop_back();
        }
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> output;
        for (int k = 0; k < n + 1; ++k) {
            std::vector<int> curr;
            backtrack(0, curr, nums, n, k, output);
        }
        return output;
    }
};


/*
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
*/