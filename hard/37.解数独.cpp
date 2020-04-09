/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
// class Solution {
// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         pair<int, int> pos(0, 0);
//         bool finished = false;
//         pair<int, int> posBegin = (board[0][0] == '.') ? pos :
//         NextPos(board, pos);
//         BackSearch(board, finished, posBegin);
//     }

//     pair<int, int> NextPos(vector<vector<char>> &board, pair<int, int> &pos)
//     {
//         int boardSize = board.size();
//         for (int col = pos.second + 1; col < boardSize; ++col) {
//             if (board[pos.first][col] == '.') {
//                 return pair<int, int>(pos.first, col);
//             }
//         }
//         for (int row = pos.first + 1; row < boardSize; ++row) {
//             for (int col = 0; col < boardSize; ++col) {
//                 if (board[row][col] == '.') {
//                     return pair<int, int>(row, col);
//                 }
//             }
//         }
//         return pair<int, int>(-1, -1);
//     }

//     void BackSearch(vector<vector<char>> &board, bool &finished, pair<int, int> &pos)
//     {
//         int boardSize = board.size();
//         for (int n = 1; n <= 9; ++n) {
//             board[pos.first][pos.second] = n + '0';
//             if (IsValide(board, pos)) {
//                 pair<int, int> nextPos = NextPos(board, pos);
//                 if (nextPos == pair<int, int>(-1, -1)) {
//                     finished = true;
//                     return;
//                 }
//                 BackSearch(board, finished, nextPos);
//             }
//             if (finished) {
//                 return;
//             }
//             board[pos.first][pos.second] = '.';
//         }
        
//     }

//     bool IsValide(vector<vector<char>> &board, pair<int, int> &pos)
//     {
//         int boardSize = board.size();
//         vector<char> rows(boardSize + 1, 0);
//         vector<char> cols(boardSize + 1, 0);
//         vector<char> cubs(boardSize + 1, 0);
//         for (auto x : board[pos.first]) {
//             if ((x != '.') && (++cols[x - '0'] > 1)) {
//                 return false;
//             }
//         }

//         for (auto &v : board) {
//             if ((v[pos.second] != '.') && (++rows[v[pos.second] - '0'] > 1)) {
//                 return false;
//             }
//         }

//         int row = pos.first / 3 * 3;
//         int col = pos.second / 3 * 3;
//         for (int r = row; r < row + 3; ++r) {
//             for (int l = col; l < col + 3; ++l) {
//                 if ((board[r][l] != '.') && (++cubs[board[r][l] - '0'] > 1)) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    vector<set<int>> lines, columns, blocks;
    int flag = false;
    void Init(vector<vector<char>> & board)
    {
        set<int> tmp = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 0; i < 9; ++i) {
            lines.push_back(tmp);
            columns.push_back(tmp);
            blocks.push_back(tmp);
        }
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] != '.') {
                    lines[row].erase(board[row][col] - '0');
                    columns[col].erase(board[row][col] - '0');
                    blocks[row / 3+ (col / 3) * 3].erase(board[row][col] - '0');
                }
            }
        }
    }

    bool Check(int row, int col, int val)
    {
        if ((lines[row].find(val) != lines[row].end()) &&
            (columns[col].find(val) != columns[col].end()) &&
            (blocks[row / 3 + (col / 3) * 3].find(val) !=
                blocks[row / 3 + (col / 3) * 3].end())) {
            return true;
        }
        return false;
    }

    void dfs(vector<vector<char>>& board, int count)
    {
        if (count == 81) {
            flag = true;
            return;
        }
        int row = count / 9;
        int col = count % 9;
        if (board[row][col] != '.') {
            dfs(board, count + 1);
            return;
        } else {
            for (int i = 1; i <=9; ++i) {
                if (Check(row, col, i)) {
                    lines[row].erase(i);
                    columns[col].erase(i);
                    blocks[row / 3 + (col / 3) * 3].erase(i);
                    board[row][col] = i + '0';
                    dfs(board, count + 1);
                    if (flag) {
                        return;
                    } else {
                        lines[row].insert(i);
                        columns[col].insert(i);
                        blocks[row / 3 + (col / 3) * 3].insert(i);
                        board[row][col] = '.';
                    }
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        Init(board);
        dfs(board, 0);
    }

};
// @lc code=end

