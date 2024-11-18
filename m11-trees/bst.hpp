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
// This is a BST implement Set ADT
// BST can be also used to implement Map ADT
// All methods are implemented recursively as possible
template <typename T>
class BinarySearchTree {
 private:
  // private node class/struct
  struct Node {
    T key;
    Node* left;
    Node* right;
    Node(T key) : key(key), left(nullptr), right(nullptr) {}
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
    Node* newNode = new Node(node->key);
    newNode->left = copyRecursive(node->left);
    newNode->right = copyRecursive(node->right);
    return newNode;
  }

  Node* addRecursive(Node* node, T key) {
    if (node == nullptr) return new Node(key);

    if (key < node->key)
      node->left = addRecursive(node->left, key);
    else if (key > node->key)
      node->right = addRecursive(node->right, key);

    return node;
  }

  bool containsRecursive(Node* node, T key) const {
    if (node == nullptr) return false;
    if (node->key == key) return true;
    if (key < node->key)
      return containsRecursive(node->left, key);
    else
      return containsRecursive(node->right, key);
  }

  Node* removeRecursive(Node* node, T key) {
    if (node == nullptr) {
      return nullptr;
    }

    if (key == node->key) {
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
        node->key = temp->key;
        node->right = removeRecursive(node->right, temp->key);
        return node;
      }
    } else if (key < node->key)
      node->left = removeRecursive(node->left, key);
    else
      node->right = removeRecursive(node->right, key);

    return node;
  }

  void inOrderTraversalRecursive(Node* node, std::vector<T>& result) const {
    if (node == nullptr) return;
    inOrderTraversalRecursive(node->left, result);
    result.push_back(node->key);
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

  // iterative destructor using stack
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

  void insert(T key) { root = addRecursive(root, key); }

  bool contains(T key) { return containsRecursive(root, key); }

  void remove(T key) { root = removeRecursive(root, key); }

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
      result.push_back(curr->key);
      curr = curr->right;
    }
    return result;
  }
};

#endif // BST_HPP
