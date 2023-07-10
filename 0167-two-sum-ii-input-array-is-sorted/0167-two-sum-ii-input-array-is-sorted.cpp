class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int tail = numbers.size()-1;
        int head = 0;
        vector<int> res;
        while(head < tail)
        {
            if((numbers[head] + numbers[tail]) == target)
            {
                res.push_back(head+1);
                res.push_back(tail+1);
                return res;
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
    return res;
    }
};