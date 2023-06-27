class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> rowVec(9);
        vector<unordered_map<char, int>> columnVec(9);
        vector<unordered_map<char, int>> boxVec(9);
        char ran = '99';
        int cnt = 0;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    ++ran;
                    board[i][j] = ran;
                }
                columnVec[j].insert({board[i][j], 1});
                rowVec[i].insert({board[i][j], 1});
                boxVec[(i/3)*3 + ((j)/3)].insert({board[i][j], 1});
            }
            if(rowVec[i].size() != 9)
                return false;
        }
        for(auto &val: columnVec)
        {
            if (val.size() != 9)
                return false; 
        }
        for(auto &val: boxVec)
        {
            if (val.size() != 9)
                return false;     
        }
        return true;
    }
};