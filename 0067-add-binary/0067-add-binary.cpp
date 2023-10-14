class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size()-1;
        int n = b.size()-1;
        int carry = 0;
        string res = "";

        while(m >= 0 || n >= 0 || carry != 0)
        {
            int x = 0;
            if(m >= 0 && a[m] == '1')
            {
                x = 1;
            }
            int y = 0;
            if(n >= 0 && b[n] == '1')
            {
                y = 1;
            }
            res = to_string((x+y+carry)%2) + res;
            carry = (x+y+carry)/2;
            --m;
            --n;
        }
        return res;
    }
};