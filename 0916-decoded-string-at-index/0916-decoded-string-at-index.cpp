class Solution {
public:
    string decodeAtIndex(string s, int k) {

        string a;
        long long cnt = 0;
        int N = s.size();
        for(auto & c : s)
        {
            if(c > 96 and c < 123)
            {
                cnt++;
            }
            else
            {
                int i = c - '0';
                cnt = cnt*i;
            }
        }
        for (int i = N-1; i >=0; --i) {
            k =  k%cnt;
            if (k == 0 && isalpha(s[i]))
                return (string) "" + s[i];

            if (isdigit(s[i]))
                cnt /= s[i] - '0';
            else
                cnt--;
        }
        return "";

    }
};