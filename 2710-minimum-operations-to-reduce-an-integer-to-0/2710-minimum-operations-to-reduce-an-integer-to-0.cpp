class Solution {
public:
    int minOperations(long n) {
        cout << n << endl;
        int bitCountOne = __builtin_popcountl(n);
        if(bitCountOne == 1) return bitCountOne;
        return 1+min(minOperations(n+(n&(-n))), minOperations(n-(n&(-n))));
    }
};