class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, int>> rows(9);
        vector<unordered_map<int, int>> columns(9);
        vector<unordered_map<int, int>> boxes(9);

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char c = board[i][j];
                if(c != '.') {
                    int n = (int)c;
                    int box_index = (i / 3 ) * 3 + j / 3;

                    // Keep the current cell value
                    rows[i][n]++;
                    columns[j][n]++;
                    boxes[box_index][n]++;

                    // Check if this value has been already seen before
                    if(rows[i][n] > 1 || columns[j][n] > 1 || boxes[box_index][n] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};
