#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

        vector<vector<int>> orig(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                orig[row][col] = board[row][col];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int live_cells_num = 0;
                for (int index = 0; index < 8; index++)
                {
                    int new_x = i + dx[index];
                    int new_y = j + dy[index];

                    if ((new_x >= 0 && new_x < m) && (new_y >= 0 && new_y < n) && (orig[new_x][new_y] == 1))
                        live_cells_num++;
                }

                if ((live_cells_num < 2 || live_cells_num > 3) && orig[i][j] == 1)
                    board[i][j] = 0;

                if (live_cells_num == 3 && orig[i][j] == 0)
                {
                    board[i][j] = 1;
                    std::cout << i << " " << j << " " << board[i][j] << std::endl;
                }
                    

            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<int>> board = {{0, 1, 0} , {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    sol.gameOfLife(board);
    int m = board.size();
    int n = board[0].size();
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << board[i][j] << std::endl;
        }
    }
    
}