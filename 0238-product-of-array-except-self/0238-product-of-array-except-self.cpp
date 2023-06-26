class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int length = nums.size();
    std::vector<int> answer(length, 1);

    // answer[i] now contains the product of all numbers to the left
    // For the element at index '0', there are no elements to the left,
    // hence answer[0] = 1
    for (int i = 1; i < length; i++) {
        answer[i] = nums[i - 1] * answer[i - 1];
    }

    // R contains the product of all numbers to the right
    // We start with the rightmost element and work our way to the left
    int R = 1;
    for (int i = length - 1; i >= 0; i--) {
        // For the index 'i', R contains the product of all numbers to the right. 
        // We update R to include the product of R and the current number
        answer[i] = answer[i] * R;
        R *= nums[i];
    }

    return answer;
    }
};