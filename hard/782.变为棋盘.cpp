/*
 * @lc app=leetcode.cn id=782 lang=cpp
 *
 * [782] 变为棋盘
 */

// @lc code=start
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int boardSize = board.size();
        for (int row = 0; row < boardSize; ++row) {
            for (int col = 0; col < boardSize; ++col) {
                if ((board[0][0] ^ board[0][col] ^ board[row][0] ^ board[row][col]) != 0) {
                    return -1;
                }
            }
        }

        int rowNum = 0;
        int colNum = 0;
        int rowDiff = 0;
        int colDiff = 0;
        for (int idx = 0; idx < boardSize; ++idx) {
            rowNum += board[0][idx];
            colNum += board[idx][0];
            rowDiff += (board[0][idx] != (idx % 2));
            colDiff += (board[idx][0] != (idx % 2));
        }

        if ((rowNum != boardSize / 2) && (rowNum != (boardSize + 1) / 2)) {
            return -1;
        }
        if ((colNum != boardSize / 2) && (colNum != (boardSize + 1) / 2)) {
            return -1;
        }

        int res = 0;
        if (boardSize % 2 == 0) {
            res += min(rowDiff, boardSize - rowDiff);
            res += min(colDiff, boardSize - colDiff);
        } else {
            res += (rowDiff % 2 == 0) ? rowDiff : boardSize - rowDiff;
            res += (colDiff % 2 == 0) ? colDiff : boardSize - colDiff;
        }

        return res / 2;
    }
};
// @lc code=end

