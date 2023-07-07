class Solution {
public:
    int getSum(int a, int b) {
        while(a != 0)
        {
            int carry = a & b;
            b ^= a;
            a = (unsigned)carry << 1;
        }
    return b;
    }
};