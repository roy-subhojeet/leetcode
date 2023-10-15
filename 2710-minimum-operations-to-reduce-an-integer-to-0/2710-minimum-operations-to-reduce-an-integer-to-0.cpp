class Solution {
public:
int minOperations(int n){
	int power = log2(n);
	if((1 << power) == n)	return 1;
	int diff1 = minOperations(n-(1 << power));
	int diff2 = minOperations((1 << (power + 1))-n);
	return 1 + min(diff1, diff2);
}
};