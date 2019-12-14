/*
题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include <vector>
#include <assert.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool Find(int target, vector<vector<int> > array0)
    {
        int rows = array0.size();
        int cols = array0[0].size();
        int col_current = 0;
        int row_current = rows - 1;
        bool found = false;
        while (row_current >= 0 && col_current <= cols - 1)
        {
            if (array0[row_current][col_current] == target)
            {
                return true;
            }
            else if (array0[row_current][col_current] > target)
            {
                row_current--;
            }
            else
            {
                col_current++;
            }
        }
        return found;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int> > array(3);
    for (int i = 0; i < 3; i++)
        array[i].resize(3);

    // array = {{1,2,3},{2,5,9},{3,8,12}};  ## error: expected expression
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            array[i][j] = (i * j);

    Solution solution;
    bool res = solution.Find(4, array);
    assert(res==true);
    printf("demo001 success");
    return 0;
}