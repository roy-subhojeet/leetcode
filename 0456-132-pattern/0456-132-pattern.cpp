class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;

        vector<int> minArray;
        int n = nums.size() - 1;
        int minima = INT_MAX;
        for(int i = 0 ; i < nums.size(); ++i)
        {
            minima = min(minima, nums[i]);
            minArray.push_back(minima);
        }
        stack<int> viableK;
        for(int i = n; i >= 0; --i)
        {
            if(nums[i] <= minArray[i]) continue;
            while(!viableK.empty() && viableK.top() <= minArray[i]) viableK.pop();
            if(!viableK.empty() && nums[i] > viableK.top() && nums[i] > minArray[i]) return true;
            viableK.push(nums[i]);
        }
    return false;

    }
};