/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        addVector(root, 0);
        return res;
    }
    void addVector(TreeNode *root, int level)
    {
        if (root == nullptr)
        {
            return;
        }
        if (res.size() == level)
        {
            res.resize(level + 1);
        }
        if (level % 2 == 0)
        {
            res[level].push_back(root->val);
        }
        else
        {
            res[level].insert(res[level].begin(), root->val);
        }
        addVector(root->left, level + 1);
        addVector(root->right, level + 1);
    }
};