class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjMat(n, vector<pair<int, int>>());
        for(int i = 0; i < flights.size(); ++i)
        {
            adjMat[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> steps(n, INT_MAX);
        pq.push({0, src, 0});
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            if(node[2] > k+1 || node[2] > steps[node[1]]) continue; /*  node[2] > steps[node[1]]: already visited the node [remember here steps acts as a
                                                                        visited,since we are using djikistras we're sure that the cost to the already visited/processed node
                                                                        would be min. we don't need to explore again]
                                                                        node[2] > k+1: exceeding the limit, we can take this path*/
            steps[node[1]] = node[2];
            if(node[1] == dst) return node[0];
            for(auto &neighbor : adjMat[node[1]])
            {
                pq.push({node[0] + neighbor.second, neighbor.first, node[2]+1});
            }
        }

        return -1;
    }
};