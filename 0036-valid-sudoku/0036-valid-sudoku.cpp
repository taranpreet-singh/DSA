class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> row;
            unordered_map<char, int> col;
            unordered_set<char> seen;

            // for rows and cols
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (row.count(board[i][j])) {
                        return false;
                    }
                    row[board[i][j]]++;
                }

                if (board[j][i] != '.') {
                    if (col.count(board[j][i])) {
                        return false;
                    }
                    col[board[j][i]]++;
                }
            }

            // For square
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    int row = (i / 3) * 3 + j;
                    int col = (i % 3) * 3 + k;
                    if (board[row][col] == '.')
                        continue;
                    if (seen.count(board[row][col]))
                        return false;
                    seen.insert(board[row][col]);
                }
            }
        }

        return true;
    }
};