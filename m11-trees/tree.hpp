/**
 * Header only module holding generic tree declarations
 *
 * WARNING: Declarations only! Not implemented!
 */
#ifndef TREE_HPP
#define TREE_HPP
template <typename T>
struct TreeNode {
  T value;
  vector<TreeNode *> children;
  TreeNode()=default;
  TreeNode(T value): value(value) {}
};

template <typename T>
struct BinaryTreeNode {
  T value;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
  BinaryTreeNode()=default;
  BinaryTreeNode(T value): value(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class Tree {
  TreeNode *root;
 public:
  Tree(): root(nullptr) {}
  ~Tree();
  void insert(T value);
  void remove(T value);
  bool contains(T value);
};

template <typename T>
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
