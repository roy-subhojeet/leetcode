class Solution {
public:
    int totalMoney(int n) {
        int rem = n % 7;
        int div = n/7;
        long long sum = 0;
        int i = 0;
        for(i = 0; i < div; i++)
        {
            sum += (7*(i+1+7+i))/2;
        }
        if(rem > 0)
        {
            sum += (rem*(i+1+rem+i))/2;
        }
        return sum;
    }
};