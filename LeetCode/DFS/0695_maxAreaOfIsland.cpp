/*
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int cur_i, int cur_j, const vector<int> &di, const vector<int> &dj)
    {
        if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1)
            return 0;
        grid[cur_i][cur_j] = 0;
        int ans = 1;
        for (int index = 0; index != 4; ++index)
        {
            int next_i = cur_i + di[index], next_j = cur_j + dj[index];
            ans += dfs(grid, next_i, next_j, di, dj);
        }
        return ans;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        vector<int> di = {0, 0, 1, -1};
        vector<int> dj = {1, -1, 0, 0};
        for (int i = 0; i != grid.size(); ++i)
            for (int j = 0; j != grid[0].size(); ++j)
                ans = max(ans, dfs(grid, i, j, di, dj));
        return ans;
    }
};

class Solution
{
public:
    int get_island_area(vector<vector<int>> &grid, int x, int y, vector<int> &dx, vector<int> &dy)
    {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
            return 0;

        int area = 1;
        grid[x][y] = 0;
        for (auto index = 0; index < 4; index++)
        {
            int next_x = x + dx[index];
            int next_y = y + dy[index];
            area += get_island_area(grid, next_x, next_y, dx, dy);
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {

        int m = grid.size();
        if (m == 0)
        {
            return 0;
        }
        int n = grid[0].size();
        int maxarea = 0;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        for (auto i = 0; i < m; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                maxarea = max(maxarea, get_island_area(grid, i, j, dx, dy));
            }
        }

        return maxarea;
    }
};