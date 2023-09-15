class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        vector<int> visited(points.size(), 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int ans = 0;
        int edgesUsed = 0;
        minHeap.push({0, 0});

        while(edgesUsed < points.size())
        {
            auto itr = minHeap.top();
            minHeap.pop();
            int current = itr.second;
            if(visited[current]) continue;
            visited[current] = 1;
            ans += itr.first;
            
            

            for(int j = 0; j < points.size(); ++j)
            {
                if(visited[j]) continue;
                int distance = abs(points[current][0] - points[j][0]) + abs(points[current][1] - points[j][1]);
                minHeap.push({distance, j});
            }

            edgesUsed++;
        }
        return ans;
        
    }
};