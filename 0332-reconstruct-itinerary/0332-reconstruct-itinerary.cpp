class Solution {
public:

    vector<string> ans;
    unordered_map<string, priority_queue<string, vector<string>, greater<>>> mp;
    

    void formItenary(string from)
    {
        while(!mp[from].empty())
        {
            string to = mp[from].top();
            mp[from].pop();
            formItenary(to);
        }
        ans.push_back(from);
        /*
        if(mp[from].empty()) return;
        string to = mp[from].top();
        ans.push_back(to);
        mp[from].pop();
        formItenary(to);
        */
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto & ticket : tickets)
        {
            mp[ticket[0]].push(ticket[1]);
        }
        
        formItenary("JFK");
        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};