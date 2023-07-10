class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for(auto &c: s)
        {
            if(isalnum(c))
                res += tolower(c);
        }
        int head = 0;
        int tail = res.size()-1;
        bool flg = true;
        while(tail >= 0)
        {
            if(res[head] != res[tail])
                return false;
            ++head;
            --tail;
        }
        return flg;
    }
};