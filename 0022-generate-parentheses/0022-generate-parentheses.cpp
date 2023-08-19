class Solution {
public:

    void backtracking(int n, int close, int open, string s)
    {
        if(s.size() == 2*n)
        {
            result.push_back(s);
            return;
        }
        if(open < n) backtracking(n, close, open+1, s+"(");
        if(close < open) backtracking(n, close+1, open, s+")");
    }
    vector<string> generateParenthesis(int n) {

        backtracking(n, 0, 0, "");
        return result;
    }
private:
    vector<string> result;
};