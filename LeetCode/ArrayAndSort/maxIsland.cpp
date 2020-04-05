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