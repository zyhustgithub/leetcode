/*
 * @lc app=leetcode.cn id=864 lang=cpp
 *
 * [864] 获取所有钥匙的最短路径
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct Node {
    int x;
    int y;
    int z;
    int d;

    Node(int _x, int _y, int _z, int _d) : x(_x), y(_y), z(_z), d(_d) {}
};

struct HashKey {
    size_t operator()(const Node &obj) const
    {
        return std::hash<std::string>()(to_string(obj.x) + to_string(obj.y) + to_string(obj.z));
    }
};

struct HashCmp {
    bool operator()(const Node &lhs, const Node &rhs) const
    {
        return std::tie(lhs.x, lhs.y, lhs.z) == std::tie(rhs.x, rhs.y, rhs.z);
    }
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        static int next[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
        unordered_set<Node, HashKey, HashCmp> seen;
        queue<Node> q;
        int locks = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == '@') {
                    seen.insert(Node(row, col, 0, 0));
                    q.push({row, col, 0, 0});
                }

                if (IsKey(grid[row][col])) {
                    locks |= (1 << (grid[row][col] - 'a'));
                }
            }
        }

        while (!q.empty()) {
            Node curNode = q.front();
            q.pop();

            if (curNode.z == locks) {
                return curNode.d;
            }

            for (int n = 0; n < 4; ++n) {
                int nx = curNode.x + next[0][n];
                int ny = curNode.y + next[1][n];

                if (!IsValid(nx, ny) || (grid[nx][ny] == '#')) {
                    continue;
                }

                if (IsLock(grid[nx][ny]) && !CanPass(grid[nx][ny], curNode.z)) {
                    continue;
                }

                int nz = curNode.z;
                if (IsKey(grid[nx][ny])) {
                    nz |= (1 << (grid[nx][ny] - 'a'));
                }

                Node nextNode(nx, ny, nz, curNode.d + 1);
                if (seen.count(nextNode) > 0) {
                    continue;
                }

                seen.insert(nextNode);
                q.push(std::move(nextNode));
            }
        }
        return -1;
    }

    bool CanPass(char ch, int keys)
    {
        return (((1 << (ch - 'A')) & keys) != 0);
    }

    bool IsValid(int x, int y)
    {
        return (x >= 0) && (x < rows) && (y >= 0) && (y < cols);
    }

    bool IsKey(char ch)
    {
        return (ch >= 'a') && (ch <= 'f');
    }

    bool IsLock(char ch)
    {
        return (ch >= 'A') && (ch <= 'F');
    }

private:
    int rows = 0;
    int cols = 0;
};

#if 0
int main(int argc, char *argv[])
{
    Solution s;
    vector<string> grid = {"@.a.#","###.#","b.A.B"};
    int res = s.shortestPathAllKeys(grid);
    cout << res << endl;
    return 0;
}
#endif
// @lc code=end
