
template <class T>
class TreeNode {
 public:
  T value;
  vector<TreeNode *> children;
};

template <class T>
class BinaryTreeNode {
 public:
  T value;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
  BinaryTreeNode *parant;
};

template <class T>
class Tree {
 private:
  TreeNode *root;
 public:
  void insert(T value);
  void remove(T value);
  int height();
  void printAll();
};

template <class T>
class BinaryTree {
 private:
  BinaryTreeNode *root;
 public:
  void insert(T value);
  void remove(T value);
};