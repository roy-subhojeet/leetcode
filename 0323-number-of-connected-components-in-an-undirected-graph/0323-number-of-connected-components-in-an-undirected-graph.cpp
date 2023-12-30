class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjMat(n, vector<int>());
        for(int i = 0; i < edges.size(); ++i)
        {
            adjMat[edges[i][0]].push_back(edges[i][1]);
            adjMat[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        stack<int> st;
        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            if(!visited[i])
            {
                st.push(i);
                while(!st.empty())
                {
                    auto s = st.top();
                    st.pop();
                    visited[s] = true;
                    for(auto &e : adjMat[s])
                    {
                        if(!visited[e]) st.push(e);
                    }
                }
                ++count;
            }
        }
        return count;
    }
};