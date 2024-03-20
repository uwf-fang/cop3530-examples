/**
 * @file tree.hpp
 * @author Ian Fang
 * @brief Header only module holding generic tree declarations
 *        These tree implements Set ADTs
 *
 * WARNING: Declarations only! Not implemented!
 */
#ifndef TREE_HPP
#define TREE_HPP


// General tree node
template <typename T>
struct TreeNode {
  T value;
  vector<TreeNode *> children;
  TreeNode()=default;
  TreeNode(T value): value(value) {}
};

// Binary tree node
template <typename T>
struct BinaryTreeNode {
  T value;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
  BinaryTreeNode()=default;
  BinaryTreeNode(T value): value(value), left(nullptr), right(nullptr) {}
};

// General tree
template <typename T>
class Tree {
  TreeNode *root;
 public:
  Tree(): root(nullptr) {}
  Tree(const Tree &other);
  Tree &operator=(const Tree &other);
  ~Tree();
  void add(T value);
  void remove(T value);
  bool contains(T value);
};

template <typename T>
class BinaryTree {
  BinaryTreeNode *root;
 public:
  BinaryTree(): root(nullptr) {}
  BinaryTree(const BinaryTree &other);
  BinaryTree &operator=(const BinaryTree &other);
  ~BinaryTree();
  void add(T value);
  void remove(T value);
  bool contains(T value);
  void printInOrder() const;
};

#endif
