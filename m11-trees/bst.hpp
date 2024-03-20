/**
 * @file bst.hpp
 * @author Ian Fang
 *
 * @brief Binary search tree class template
 *
 */
#ifndef BST_HPP
#define BST_HPP

#include <stack>
#include <vector>

// Binary search tree class template
// All methods are implemented recursively as possible
template <typename T>
class BinarySearchTree {
 private:
  // private node class/struct
  struct Node {
    T value;
    Node* left;
    Node* right;
    Node(T value) : value(value), left(nullptr), right(nullptr) {}
  };

  Node* root;

  void deleteSubtree(Node* root) {
    if (root == nullptr) return;
    deleteSubtree(root->left);
    deleteSubtree(root->right);
    delete root;
    root = nullptr;
  }

  Node* copyRecursive(Node* node) {
    if (node == nullptr) return nullptr;
    Node* newNode = new Node(node->value);
    newNode->left = copyRecursive(node->left);
    newNode->right = copyRecursive(node->right);
    return newNode;
  }

  Node* addRecursive(Node* node, T value) {
    if (node == nullptr) return new Node(value);

    if (value < node->value)
      node->left = addRecursive(node->left, value);
    else if (value > node->value)
      node->right = addRecursive(node->right, value);

    return node;
  }

  bool containsRecursive(Node* node, T value) const {
    if (node == nullptr) return false;
    if (node->value == value) return true;
    if (value < node->value)
      return containsRecursive(node->left, value);
    else
      return containsRecursive(node->right, value);
  }

  Node* removeRecursive(Node* node, T value) {
    if (node == nullptr) {
      return nullptr;
    }

    if (value == node->value) {
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
      } else if (node->left == nullptr) {
        Node* temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        Node* temp = node->left;
        delete node;
        return temp;
      } else {
        Node* temp = findMinNode(node->right);
        node->value = temp->value;
        node->right = removeRecursive(node->right, temp->value);
        return node;
      }
    } else if (value < node->value)
      node->left = removeRecursive(node->left, value);
    else
      node->right = removeRecursive(node->right, value);

    return node;
  }

  void inOrderTraversalRecursive(Node* node, std::vector<T>& result) const {
    if (node == nullptr) return;
    inOrderTraversalRecursive(node->left, result);
    result.push_back(node->value);
    inOrderTraversalRecursive(node->right, result);
  }

  Node* findMinNode(Node* node) const {
    Node* current = node;
    while (current && current->left != nullptr) current = current->left;
    return current;
  }

 public:
  BinarySearchTree() : root(nullptr) {}

  BinarySearchTree(const BinarySearchTree &other) {
    root = copyRecursive(other.root);
  }

  BinarySearchTree &operator=(const BinarySearchTree &other) {
    if (this != &other) {
      deleteSubtree(root);
      root = copyRecursive(other.root);
    }
    return *this;
  }

  // Easy way to delete the tree recursively
  // ~BinarySearchTree() { deleteSubtree(root); }

  // destructor using stack
  ~BinarySearchTree() {
    // iterative destructor using stack
    if (root == nullptr) return;  // empty tree
    std::stack<Node*> st;
    Node* curr = root;
    while (curr != nullptr || !st.empty()) {
      if (curr != nullptr) {
        st.push(curr);
        curr = curr->left;
      } else {
        curr = st.top();
        st.pop();
        Node* temp = curr;
        curr = curr->right;
        delete temp;
      }
    }
  }

  void add(T value) { root = addRecursive(root, value); }
  bool contains(T value) { return containsRecursive(root, value); }
  void remove(T value) { root = removeRecursive(root, value); }
  std::vector<T> inOrderTraversal() const {
    std::vector<T> result;
    inOrderTraversalRecursive(root, result);
    return result;
  }
  std::vector<T> inOrderTraversalIterative() {
    // implement using stack
    std::vector<T> result;
    std::stack<Node*> st;
    Node* curr = root;

    while (curr != nullptr || !st.empty()) {
      while (curr != nullptr) {
        st.push(curr);
        curr = curr->left;
      }
      curr = st.top();
      st.pop();
      result.push_back(curr->value);
      curr = curr->right;
    }
    return result;
  }
};

#endif  // BST_HPP
