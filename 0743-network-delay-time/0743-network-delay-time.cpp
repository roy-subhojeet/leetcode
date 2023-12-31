class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create an adjacency matrix where each element is a vector of pairs.
        // Each pair consists of a destination node and the time it takes to reach that node.
        vector<vector<pair<int, int>>> adjMat(n+1, vector<pair<int, int>>());
        
        // Iterate through the 'times' vector to build the adjacency matrix.
        // Each element in 'times' represents an edge in the format [u, v, w] where
        // u is the source node, v is the destination node, and w is the travel time.
        for(int i = 0; i < times.size(); ++i) {
            adjMat[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        // Use a min priority queue to select the node with the minimum travel time during each step of the algorithm.
        // The priority queue stores pairs of node and the time taken to reach it.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Start from node 'k' with an initial time of 0 and add it to the priority queue.
        pq.push({k, 0});
        
        // Initialize a vector to store the minimum time to reach each node. Set all times to INT_MAX initially.
        vector<int> minTimeToNode(n+1, INT_MAX);
        minTimeToNode[k] = 0;
        
        // Continue the loop until the priority queue is empty.
        while(!pq.empty()) {
            // Extract the node with the minimum travel time from the priority queue.
            auto s = pq.top();
            pq.pop();

            // Iterate over all neighbors of the current node.
            for(auto &neighbor : adjMat[s.first]) {
                // If the time to reach the neighbor via the current node is less than the previously known time,
                // update the time to reach the neighbor.
                if(minTimeToNode[neighbor.first] > s.second+neighbor.second) {
                    minTimeToNode[neighbor.first] = s.second+neighbor.second;
                    // Add the neighbor to the priority queue with the updated time.
                    pq.push({neighbor.first, s.second+neighbor.second});
                }
            }
        }

        int dis = INT_MIN;
        // Iterate over the minTimeToNode array to find the maximum time.
        for(int i = 1; i < minTimeToNode.size(); ++i) dis = max(dis, minTimeToNode[i]);
        
        // If the maximum time is INT_MAX, it means there are nodes that couldn't be reached.
        // Return -1 in this case. Otherwise, return the maximum time.
        return dis == INT_MAX ? -1 : dis;
    }

};
/*
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjMat(n+1, vector<pair<int, int>>());
        for(int i = 0; i < times.size(); ++i)
        {
            adjMat[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<bool> visited(n+1, false);
        stack<pair<int, int>> st;
        st.push({k, 0});
        int dis = 0;
        while(!st.empty())
        {
            auto s = st.top();
            st.pop();
            dis = max(dis, s.second);
            visited[s.first] = true;
            for(auto &neighbor : adjMat[s.first])
            {
                if(visited[neighbor.first] == true) continue;
                st.push({neighbor.first, s.second+neighbor.second});
            }
        }
        for(int i = 1; i < visited.size(); ++i) if(visited[i] == false) return -1;
        return dis;
    }
};
*/