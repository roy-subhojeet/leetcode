class Solution {
public:
    bool closeStrings(string word1, string word2) {

        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for(auto & i: word1)
        {
            ++v1[i - 'a'];
        }
        for(auto & j: word2)
        {
            ++v2[j - 'a'];
            if(v1[j - 'a'] == 0) return false;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return v1==v2;

    }
};