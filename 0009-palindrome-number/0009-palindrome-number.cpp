class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        vector<int> num;
        while(x != 0)
        {
            num.push_back(x%10);
            x = x/10;
        }
        int size = num.size();
        cout << size;
        for(auto n : num)
        {
            if(n == num[size-1])
                size--;
            else
                return false;
        }
    return true;
    }
};