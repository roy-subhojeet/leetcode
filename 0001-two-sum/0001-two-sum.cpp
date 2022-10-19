class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> array;
        
        for(auto itr = nums.begin(); itr < nums.end(); itr++)
        {
            for(auto itr2 = itr + 1; itr2 <nums.end(); itr2++)
            {
                int res = *itr+*itr2;
                int index_2 = 0;
                if(target == res)
                {
                    array.push_back(distance(nums.begin(), itr));
                    array.push_back(distance(nums.begin(), itr2));
                }
            }
        }
        return array;
    }
};