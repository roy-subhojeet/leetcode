class Solution {
public:
    int countHomogenous(string s) {
        long long  rc = 1;
        long long ans = 0;
        for(int i = 0; i < s.size()-1; ++i)
        {
            if(s[i] == s[i+1]) ++rc;
            else 
            {
                if(rc != 1)ans += rc*(rc+1)/2;
                else ans += 1;
                rc = 1;
            }
        }
                if(rc != 1)ans += rc*(rc+1)/2;
                else ans += 1;
        return ans % 1000000007;
        
    }
};