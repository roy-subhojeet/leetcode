class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string ans;
        bool neg = false;
        if(num < 0) neg = true;
        num = abs(num);
        while(num > 0)
        {
            ans = to_string(num%7) + ans;
            num = num/7;
        }
        //reverse(ans.begin(), ans.end());
        return neg == true ? string("-")+ans : ans;
    }
};