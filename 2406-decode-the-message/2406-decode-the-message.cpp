class Solution {
public:
    string decodeMessage(string key, string message) {

        vector<char> hashMap(26, 0);
        string ans;
        char c = 'a';
        for(auto & i: key)
        {
            if(i != ' ')
            {
                if(hashMap[i - 'a'] == 0)
                {                
                    hashMap[i - 'a'] = c;
                    c+=1;
                }
            }
        }

        for(auto & i : message)
        {
            if(i == ' ') 
            {
                ans+= ' ';
                continue;
            }
            ans += hashMap[i - 'a'];
        }
        
        return ans;
    }
};