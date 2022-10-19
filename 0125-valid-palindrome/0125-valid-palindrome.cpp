class Solution {
public:
    bool isPalindrome(string s) {
    bool res = true;
    if(s.empty())
        return true;
    int j = 0;
    for(int i = 0; i< s.length(); i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') ||
           (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            s[j] = s[i];
            s[j] = tolower(s[j]);
            j++;
        }
    }
    s= s.substr(0,j);
    int end = s.length()-1;
    for(int itr = 0; itr < s.length(); itr++)
    {
        if(s[itr] != s[end])
        {
            res = false;
            break;
        }
        end--;
    }
    return res;
    }
};