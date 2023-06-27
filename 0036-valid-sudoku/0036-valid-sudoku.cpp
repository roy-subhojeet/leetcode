class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //vector<unordered_map<int, int>> rows(9);
        //vector<unordered_map<int, int>> columns(9);
        //vector<unordered_map<int, int>> boxes(9);

        int rows[9][9] = {0};
        int columns[9][9] = {0};
        int boxes[9][9] = {0};

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char c = board[i][j];
                if(c != '.') {
                    int n = (int)(c - '0') - 1; // Subtract '1' to make it 0-indexed
                    int box_index = (i / 3 ) * 3 + j / 3;

                    // Check if this value has been already seen before
                    if(rows[i][n] > 0 || columns[j][n] > 0 || boxes[box_index][n] > 0)
                        return false;

                    // Keep the current cell value
                    rows[i][n]++;
                    columns[j][n]++;
                    boxes[box_index][n]++;
                }
            }
        }
        return true;
    }
};
