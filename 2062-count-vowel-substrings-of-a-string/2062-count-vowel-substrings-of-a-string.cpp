class Solution {
public:
int countVowelSubstrings(string w) {
    /* j: initial index in the stream where a vowel is encountered
       k: k-1 is the starting index for the smallest window with all vowels
       i: current position
     vow: unique count of vowels
     cnt: total no. of vowel substrings
    */
    int j = 0, k = 0, vow = 0, cnt = 0;
    // Map to store count of each vowel found in the stream
    unordered_map<char, int> m {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
    for (int i = 0; i < w.size(); ++i) {
        if (m.count(w[i])) { // Vowel found in the stream
            ++m[w[i]]; // increment the count of the vowel in the map
            if(m[w[i]] == 1){
                vow += 1; // Increment the count only for unique vowel found
            }
            for (; vow == 5; ++k){ // if all unique vowel found in the stream increment k
                --m[w[k]]; // decrement the count of vowel in the map
                if(m[w[k]] == 0) // if that vowel's count becomes 0
                {
                    vow -= 1; // decrement the unique vowel count
                }
            }
            //cout << "k: "<< k << " i: " << i<<endl;
            cnt += k - j; // the number of valid substrings in the stream
            //cout << "count: " << cnt << endl;
        }
        else {
            m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = vow = 0; // reset when consonant encountered
            j = k = i + 1; // set j and k to next position
        }
    }
    return cnt;
}
};