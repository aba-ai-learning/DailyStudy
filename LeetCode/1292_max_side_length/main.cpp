#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution
{
public:
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        int m = mat.size();
        if (m == 0)
        {
            return 0;
        }
        int n = mat[0].size();

        vector<vector<int>> mat_sum(m + 1, vector<int>(n + 1));
        int sum1 = 0, sum2 = 0;

        for (auto i = 0; i < m; ++i)
        {
            sum1 += mat[i][0];
            mat_sum[i][0] = sum1;
        }
        for (auto j = 0; j < n; ++j)
        {
            sum2 += mat[0][j];
            mat_sum[0][j] = sum2;
        }

        for (auto i = 1; i < m; ++i)
        {
            for (auto j = 1; j < n; ++j)
            {
                mat_sum[i][j] = mat[i][j] + mat_sum[i - 1][j] + mat_sum[i][j - 1] - mat_sum[i - 1][j - 1];
            }
        }

        int matrix_min_side = min(m, n);
        if (mat_sum[m - 1][n - 1] <= threshold)
        {
            return matrix_min_side;
        }

        int square_max_side = matrix_min_side;

        int i = 0, j = 0;
        while (m > i && n > j)
        {
            if (m != n)
            {
                if (m > n)
                {
                    int delta = m - n;
                    while (delta > 0)
                    {
                        int value1 = mat_sum[m - 1][n] + mat_sum[i][j] + mat_sum[m - 1][j] - mat_sum[i][n];
                        int value2 = mat_sum[m][n] + mat_sum[i + 1][j] + mat_sum[m][j] - mat_sum[i + 1][n];
                        if (value1 < value2)
                        {
                            m--;
                        }
                        else
                        {
                            i++;
                        }
                        delta--;
                    }
                }
                else
                {
                    int delta = n - m;
                    while (delta > 0)
                    {
                        int value1 = mat_sum[m][n - 1] + mat_sum[i][j] + mat_sum[m][j] - mat_sum[i][n - 1];
                        int value2 = mat_sum[m][n] + mat_sum[i][j + 1] + mat_sum[m][j + 1] - mat_sum[i][n];
                        if (value1 < value2)
                        {
                            n--;
                        }
                        else
                        {
                            j++;
                        }
                        delta--;
                    }
                }
            }
            else
            {
                int value = mat_sum[m][n] + mat_sum[i][j] + mat_sum[m][j] - mat_sum[i][n];
                if (value <= threshold)
                {
                    return m - i;
                }
                else
                {
                    int value1 = mat_sum[m - 1][n - 1] + mat_sum[i][j] + mat_sum[m - 1][j] - mat_sum[i][n - 1];
                    int value2 = mat_sum[m][n] + mat_sum[i + 1][j + 1] + mat_sum[m][j + 1] - mat_sum[i + 1][n];
                    if (value1 < value2)
                    {
                        m--;
                        n--;
                    }
                    else
                    {
                        i++;
                        j++;
                    }
                }
            }
        }

        return m - i;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<int>> mat= {{2,3,1},{1,3,4}};
    int res = sol.maxSideLength(mat,6);
    cout << res << endl;
}