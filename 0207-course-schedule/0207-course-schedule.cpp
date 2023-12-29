class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegreeV(numCourses);
        vector<vector<int>> adjMat(numCourses, vector<int>());
        for(auto & n : prerequisites)
        {
            adjMat[n[1]].push_back(n[0]);
            inDegreeV[n[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            
            if(inDegreeV[i] == 0) q.push(i); // Push the course number (index), not the in-degree.
        }

        vector<int> topoOrderedList;
        while(!q.empty())
        {
            auto topE = q.front();
            q.pop();
            topoOrderedList.push_back(topE);
            for(auto & l : adjMat[topE])
            {
                --inDegreeV[l];
                if(inDegreeV[l] == 0) q.push(l);
            }
        }
        return topoOrderedList.size() == numCourses;
    }
};