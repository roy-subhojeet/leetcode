class Solution {
public:
    bool backspaceCompare(string s, string t) {

        return parseString(s) == parseString(t);
        
    }

string parseString(string &parse)
{
    int i = 0;
    while (i < parse.size())
    {
        if (parse[i] == '#')
        {
            if (i > 0) // Check if it's not the first character
            {
                parse.erase(i-1, 2); // Remove two characters
                i -= 2; // Adjust index after erasing
            }
            else
            {
                parse.erase(i, 1); // Only remove one character
                i--; // Adjust index after erasing
            }
        }
        i++;
    }
    return parse;
}

};