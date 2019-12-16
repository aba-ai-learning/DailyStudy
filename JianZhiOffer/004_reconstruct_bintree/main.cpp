/**
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

前序遍历：根结点 ---> 左子树 ---> 右子树

中序遍历：左子树---> 根结点 ---> 右子树

后序遍历：左子树 ---> 右子树 ---> 根结点

层次遍历：只需按层次遍历即可

 */

#include <vector>
#include <iostream>

using namespace std;
 //Definition for binary tree
 struct TreeNode
 {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
 };

 class Solution
 {
 public:
     TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
     {
        if (pre.size() == 0)
            return nullptr;
        TreeNode *root = new TreeNode(pre[0]);
        int root_index_vin = 0;
        vector<int> pre_left, pre_right, vin_left, vin_right;
        for(int i = 0; i < vin.size(); i++)
        {
           if(vin[i] == pre[0])
           {
              root_index_vin = i;
              break;
           }
        }
        for(int i=0; i < root_index_vin; i++)
        {
           pre_left.push_back(pre[i+1]);
           vin_left.push_back(vin[i]);
        }
        for (int i = root_index_vin+1; i < vin.size(); i++)
        {
           pre_right.push_back(pre[i]);
           vin_right.push_back(vin[i]);
        }
        root->left = reConstructBinaryTree(pre_left, vin_left);
        root->right = reConstructBinaryTree(pre_right, vin_right);
        return root;
     }
};

void PrintTreeNode(const TreeNode *pNode)
{
   if (pNode != nullptr)
   {
      printf("value of this node is: %d\n", pNode->val);

      if (pNode->left != nullptr)
         printf("value of its left child is: %d.\n", pNode->left->val);
      else
         printf("left child is nullptr.\n");

      if (pNode->right != nullptr)
         printf("value of its right child is: %d.\n", pNode->right->val);
      else
         printf("right child is nullptr.\n");
   }
   else
   {
      printf("this node is nullptr.\n");
   }
   printf("\n");
}

void PrintTree(const TreeNode *pRoot)
{
   PrintTreeNode(pRoot);
   if (pRoot != nullptr)
   {
      if (pRoot != nullptr)
      {
         if (pRoot->left != nullptr)
            PrintTree(pRoot->left);
         if (pRoot->right != nullptr)
            PrintTree(pRoot->right);
      }
   }
}

int main(int argc, char* argv[])
{
   vector<int> pre = {1,2,4,7,3,5,6,8};
   vector<int> vin = {4,7,2,1,5,3,8,6};
   // const int length = 8;
   // int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
   // int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
   // vector<int> pre, vin;
   // printf("The preorder sequence is: ");
   // for (int i = 0; i < length; ++i)
   // {
   //    pre.push_back(preorder[i]);
   //    printf("%d ", preorder[i]);
   // }
   // printf("\n");

   // printf("The inorder sequence is: ");
   // for (int i = 0; i < length; ++i)
   // {
   //    vin.push_back(inorder[i]);
   //    printf("%d ", inorder[i]);
   // }
   // printf("\n");


   Solution sol;
   TreeNode* root;
   root = sol.reConstructBinaryTree(pre, vin);
   PrintTree(root);
   return 0;
}