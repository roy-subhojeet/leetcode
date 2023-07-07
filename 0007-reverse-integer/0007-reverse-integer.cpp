class Solution {
public:
    int reverse(int x) {
        signed int num = x;
        signed int res = 0;
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