/**
 * @file tree.hpp
 * @brief Header only module holding generic tree declarations
 *        Not ready for use
 *
 */
#ifndef TREE_HPP
#define TREE_HPP
template <class T>
struct TreeNode {
  T value;
  vector<TreeNode *> children;
  TreeNode()=default;
  TreeNode(T value): value(value) {}
};

template <class T>
struct BinaryTreeNode {
  T value;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
  BinaryTreeNode()=default;
  BinaryTreeNode(T value): value(value), left(nullptr), right(nullptr) {}
};

template <class T>
class Tree {
  TreeNode *root;
 public:
  Tree(): root(nullptr) {}
  ~Tree();
  void insert(T value);
  void remove(T value);
  bool contains(T value);
};

template <class T>
class BinaryTree {
  BinaryTreeNode *root;
 public:
  BinaryTree(): root(nullptr) {}
  ~BinaryTree();
  void insert(T value);
  void remove(T value);
  bool contains(T value);
  void printInOrder() const;
};

#endif
