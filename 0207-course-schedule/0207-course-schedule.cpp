class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacencyList(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto prereq: prerequisites)
        {
            adjacencyList[prereq[1]].push_back(prereq[0]);
            inDegree[prereq[0]]++;
        }
        stack<int> stk;
        for(int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
                stk.push(i);
        }
        int removedDependency = 0;
        while(!stk.empty())
        {
            int course = stk.top();
            cout<<course <<endl;
            removedDependency++;
            stk.pop();
            cout << "for >>"<<endl;
            for (auto cou: adjacencyList[course])
            {
                cout << cou;
                --inDegree[cou];
                if(inDegree[cou] == 0)
                    stk.push(cou);
            }
        }
        return (removedDependency == numCourses);
    }
};