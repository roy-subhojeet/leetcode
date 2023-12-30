class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<vector<int>> adjMat(n, vector<int>());
        map<int, int> parentMap;

        for(int i = 0 ; i < edges.size(); ++i)
        {
            adjMat[edges[i][0]].push_back(edges[i][1]);   
            adjMat[edges[i][1]].push_back(edges[i][0]);   
        }
        stack<int> st;
        st.push(0);
        parentMap[0] = -1;
        while(!st.empty())
        {
            auto s = st.top();
            st.pop();
            for(auto & e : adjMat[s])
            {
                if(parentMap[s] == e) continue;
                if(parentMap.find(e) != parentMap.end()) return false;
                parentMap[e] = s;
                st.push(e);
            }
        }
        //for(auto v : visited) if(v == false) return false;

        return parentMap.size() == n;

    }
};