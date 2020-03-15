/*
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 num1 成为一个有序数组。

 

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 

示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

set容器, 插入元素自动排序（红黑树方法）
其中multiset允许重复的数据
而set只会保存不同的数据
*/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        multiset<int> a;
        for (int i = 0; i < m; i++)
            a.insert(nums1[i]);
        for (int i = 0; i < n; i++)
            a.insert(nums2[i]);
        nums1.clear();
        for (auto i = a.begin(); i != a.end(); i++)
            nums1.push_back(*i);
    }
};