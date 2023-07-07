class Solution {
public:
    int reverse(int x) {
        if(x >= pow(2, 31) || x <= pow(-2, 31))
            return 0;
        int num = x;
        int res = 0;
        while(num != 0)
        {
            if(res >= pow(2, 31)/10 || res <= pow(-2, 31)/10)
                return 0;
            res = res*10 + num%10;
            num = num /10;
        }
        return res;
        
    }
};