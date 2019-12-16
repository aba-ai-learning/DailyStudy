/*
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.size() == 0)
            return 0;
        for(int i = 0; i < rotateArray.size() - 1; i++)
        {
            if(rotateArray[i] > rotateArray[i+1])
                return rotateArray[i+1];
        }
    }
};

int main(int argc, char* argv[])
{
    vector<int> input = {3, 4, 5, 1, 2};
    Solution sol;
    int min_num = sol.minNumberInRotateArray(input);
    assert(min_num == 1);
    cout << "success";

}