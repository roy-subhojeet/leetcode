class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int M = matrix.size() - 1;
        int N = matrix[0].size() - 1;
        int left = 0;
        int right = M; 
        int mid = 0;
        while(left <= right)
        {
            mid =  right  - (right - left)/2;
            if(matrix[mid][0] <= target && matrix[mid][N] >= target)
            {
                int l = 0;
                int r = N;
                while(l <= r)
                {
                    int m = r - (r-l)/2;
                    if(matrix[mid][m] == target) return true;
                    else if(matrix[mid][m] > target) r = m - 1;
                    else l = m + 1;
                }
                return false;
            }
            else if(matrix[mid][0] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
        
    }
};