class Solution {
public:
int minOperations(long n) {
    int one = __builtin_popcountl(n);
    if (one <= 1) return one;
    return 1 + min(minOperations(n+(n&(-n))), minOperations(n-(n&(-n))));
}
};