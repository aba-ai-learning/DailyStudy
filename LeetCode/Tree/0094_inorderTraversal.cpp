/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/
/*
递归方案
class Solution
{
public:
   vector<int> res;
   vector<int> inorderTraversal(TreeNode *root)
   {
      if (root)
      {
         inorderTraversal(root->left);
         res.push_back(root->val);
         inorderTraversal(root->right);
      }

      return res;
   }
};

*/


//迭代方案
class Solution
{
public:
   vector<int> inorderTraversal(TreeNode *root)
   {
      vector<int> res;
      stack<TreeNode *> s;
      TreeNode *top;
      TreeNode *curr = root;

      while (curr != nullptr || !s.empty())
      {
         while (curr != nullptr)
         {
            s.push(curr);
            curr = curr->left;
         }
         if (!s.empty())
         {
            top = s.top();
            s.pop();
         }

         res.push_back(top->val);

         curr = top->right;
      }

      return res;
   }
};