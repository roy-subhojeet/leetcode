class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int length = nums.size();
    std::vector<int> answer(length, 1);
    int productFromLeft = 1;
    int productFromRight = 1;

    for(int i = 0; i < length; i++)
    {
        answer[i] *= productFromLeft;
        productFromLeft *= nums[i];
        answer[length-i-1] *= productFromRight;
        productFromRight *= nums[length-i-1];
    }
    return answer;
    }
};