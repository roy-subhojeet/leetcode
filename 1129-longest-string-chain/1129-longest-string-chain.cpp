class Solution {
public:
    int longestStrChain(vector<string>& words) 
    {

        int n = words.size();
        unordered_map<int,vector<string>> order;
        unordered_map<string,int> dp;
        for(int i = 0;i < n;i++)
        {
            order[words[i].length()].push_back(words[i]);
            dp[words[i]] =1;
        }
        int count = 1;
        for(int i = 2;i<=16;i++)
        {

            if(order.count(i) && order.count(i-1))
            {
                vector<string> prev = order[i-1];
                vector<string> curr = order[i];
                for(auto c:curr)
                {
                    for(auto p :prev)
                    {
                        bool ret = isSequence(p,c);
                        if(ret)
                        {
                            dp[c] = max(dp[c],dp[p] +1);
                            count = max(count,dp[c]); 
                        }
                    }
                }


            }
        }
        return count;
    }
    bool isSequence(string s,string t)
    {
        int j = 0;
        for(int i = 0;i< t.length();i++)
        {
            if(s[j] == t[i])
            {
                j++;
            }
        }
        return j == s.length();
    }
};