class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long countLeft = 1;
        long long max_l = 0;
        for(auto &c: text)
        {
            if(c == pattern[1]) 
            {

                max_l += countLeft;
            }
            if(c == pattern[0]) ++countLeft;
        }
        long long countRight = 1;
        long long max_r = 0;
        for(int i = text.size()-1; i >=0; --i)
        {
            if(text[i] == pattern[0]) max_r += countRight;
            if(text[i] == pattern[1]) ++countRight;
        }
        return max(max_l, max_r);
        
    }
};