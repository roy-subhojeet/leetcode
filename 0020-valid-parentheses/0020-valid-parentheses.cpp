class Solution {
public:
    bool isValid(string s) {

        unordered_map<char, char> mp {
            {'}', '{'},
            {')', '('},
            {']', '['}
        };

        stack<char> st;

        for(auto &c : s)
        {
            auto itr = mp.find(c);
            if(itr != mp.end())
            {
                if(st.size() == 0 || itr->second != st.top()) return false;
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        return st.size() == 0;
    }
};