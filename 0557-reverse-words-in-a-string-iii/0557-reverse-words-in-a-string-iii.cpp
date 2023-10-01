class Solution {
public:
    string reverseWords(string s) {
        string fin;
        string ans;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ' ')
            {
                reverse(ans.begin(), ans.end());
                ans += ' ';
                fin += ans;
                ans = "";
            }
            else
            ans += s[i];
        }
        reverse(ans.begin(), ans.end());
        fin +=ans;
        return fin;
    }
};