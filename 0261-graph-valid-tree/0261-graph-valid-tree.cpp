class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // A tree must have exactly n - 1 edges (where n is the number of nodes).
        // If not, it can't be a valid tree.
        if(edges.size() != n-1) return false;

        // Adjacency matrix to represent the graph.
        vector<vector<int>> adjMat(n, vector<int>());
        // A map to track the parent of each node.
        map<int, int> parentMap;

        // Construct the graph: for each edge, add an entry to the adjacency matrix
        // in both directions (since it's an undirected graph).
        for(int i = 0; i < edges.size(); ++i) {
            adjMat[edges[i][0]].push_back(edges[i][1]);   
            adjMat[edges[i][1]].push_back(edges[i][0]);   
        }

        // Stack for DFS traversal.
        stack<int> st;
        // Start with node 0 and mark its parent as -1 (no parent).
        st.push(0);
        parentMap[0] = -1;

        // DFS traversal.
        while(!st.empty()) {
            auto s = st.top();
            st.pop();

            // Check the neighbors of the current node.
            for(auto & e : adjMat[s]) {
                // If the neighbor is the parent of the current node, skip it.
                if(parentMap[s] == e) continue;

                // If the neighbor has already been discovered and it's not the parent,
                // it means we have found a cycle. Thus, it's not a valid tree.
                if(parentMap.find(e) != parentMap.end()) return false;

                // Mark the current node as the parent of the neighbor and
                // push the neighbor onto the stack for further exploration.
                parentMap[e] = s;
                st.push(e);
            }
        }

        // After DFS, if we have discovered all nodes (the parent map has n entries),
        // and haven't found any cycles, then it's a valid tree.
        return parentMap.size() == n;
    }
};