class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        //mp.reserve(nums.size()); // Reserve space for the map
        int i = 0; 
        for(auto &elem: nums)
        {
            int find_elem = target - elem;
            if(mp.find(find_elem) != mp.end())
            {
                return {i, mp[find_elem]};
            }
            mp.emplace(elem, i); // Use emplace instead of operator[]
            i++;
        }
        throw runtime_error("No solution found"); // Throw an exception if no solution is found
    }
};