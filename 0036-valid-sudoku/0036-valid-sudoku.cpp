class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> row;
            unordered_map<char, int> col;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (row.count(board[i][j])){
                        return false;
                    }
                    row[board[i][j]]++;
                }

                if (board[j][i] != '.'){
                    if(col.count(board[j][i])){
                        return false;
                    }
                    col[board[j][i]]++;
                }
            }
        }

        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    if (seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }

        return true;
    }
};