class Solution {
private:
static const int MODULO = 1000000007;
public:

    long long countOrder(long long order)
    {
        if(order == 1) return 1;
        return (2*order - 1)*(order)*countOrder(order-1)%MODULO;

    }
    int countOrders(int n) {

        return countOrder(n);
        
    }
};