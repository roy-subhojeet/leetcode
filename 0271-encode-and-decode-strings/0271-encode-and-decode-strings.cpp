class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;
        for(auto &str:strs)
        {
            s += to_string(str.length()) + string(".") + str;
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        string st;
        vector<string> res;
        int i = 0;
        while(i < s.length())
        {
            auto pos = s.find(".", i);
            int length = stoi(s.substr(i, pos-i));
            res.push_back(s.substr(pos+1, length));
            i = pos + 1 + length;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));