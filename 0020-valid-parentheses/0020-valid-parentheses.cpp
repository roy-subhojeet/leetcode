class Solution {
public:
    bool isValid(string s) {
        map<char, char> charMap = {
            { ')' , '(' },
            { '}' , '{' },
            { ']' , '[' }
        };
    vector<char> list;
    for(auto ch: s)
    {
        if(list.empty() && charMap.count(ch))
        {
            return false;
        }
        else if(!charMap.count(ch))
        {
            list.push_back(ch);
        }
        else if(!list.empty() && charMap.count(ch))
        {
            if(list.back() == charMap.find(ch)->second)
                list.pop_back();
            else
                return false;
        }
    }
    if(list.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
  }
};