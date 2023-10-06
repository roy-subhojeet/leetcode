class Solution {
vector<int> memo;
public:
    int integerBreak(int n) {
        memo = vector<int>(n+1, 0);
        if(n <= 3) return n-1;
        return dp(n);
    }
    int dp(int n)
    {
        if(n <= 3) return n;

        if(memo[n] != 0) return memo[n];

        int ans = n;
        for(int i = 1; i < n; ++i)
        {
            ans = max(ans, i * dp(n-i));
        }
        memo[n] = ans;
        return ans;
    }
};

/*
In the integerBreak function:

if(n <= 3) return n-1;
This condition handles the base cases for the problem. When n is 2, the maximum product is 1 * 1 = 1, which is 2-1. When n is 3, the maximum product is 1 * 2 = 2, which is 3-1. So, for n values of 2 and 3, the function directly returns n-1.

In the dp function:

if(n <= 3) return n;
This condition is for the recursive function dp. When the recursive function is called with a value of n that is less than or equal to 3, it should return n itself. This is because, during the recursion, if we have a value of n that is 2 or 3, we don't want to break it further (as breaking it would reduce the product). For example, if we have a value of 3 during the recursion, we want to use the entire 3 rather than breaking it into 1 * 2.

In summary:

The condition in integerBreak handles the base cases for the main function.
The condition in dp ensures that during recursion, values of n that are less than or equal to 3 are not broken further.
It might seem redundant to have two separate conditions, but they serve different purposes in the context of the problem.
*/