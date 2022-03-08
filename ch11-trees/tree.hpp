#ifndef TREE_HPP
#define TREE_HPP
template <class T>
struct TreeNode {
  T value;
  vector<TreeNode *> children;
};

template <class T>
struct BinaryTreeNode {
  T value;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
  BinaryTreeNode *parant;
};

template <class T>
class Tree {
  TreeNode *root;
 public:
  void insert(T value);
  void remove(T value);
  int height();
  void printAll();
};

template <class T>
class BinaryTree {
  BinaryTreeNode *root;
 public:
  void insert(T value);
  void remove(T value);
};

#endif
