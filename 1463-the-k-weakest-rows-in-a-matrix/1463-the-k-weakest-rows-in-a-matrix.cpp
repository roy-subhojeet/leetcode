class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        int n = mat[0].size();
        int m = mat.size();

        vector<int> res(k, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0; i < mat.size(); ++i)
        {
            int count = 0;
            for(int j = 0; j < mat[0].size(); ++j)
            {
                if(mat[i][j] == 1) ++count;
            }
            pq.push({count, i});
        }

        int i= 0;
        for(int i = 0; i < res.size(); ++i)
        {
            res[i] = pq.top().second;
            pq.pop();
        }
        return res;


        
    }
};