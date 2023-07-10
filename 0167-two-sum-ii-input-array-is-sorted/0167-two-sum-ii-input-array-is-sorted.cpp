class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int tail = numbers.size()-1;
        int head = 0;
        while(head < tail)
        {
            if((numbers[head] + numbers[tail]) == target)
            {
                return {head+1, tail+1};
            }
            else if((numbers[head] + numbers[tail]) > target)
            {
                if(numbers[head] > numbers[tail])
                    ++head;
                else
                    --tail;
            }
            else
            {
                if(numbers[head] > numbers[tail])
                    --tail;
                else
                    ++head;
            }
        }
        return {};
    }
};