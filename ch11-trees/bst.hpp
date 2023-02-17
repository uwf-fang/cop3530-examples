/**
 * @file bst.hpp
 * @brief Binary search tree class template
 *
 */
#ifndef BST_HPP
#define BST_HPP

#include <iostream>

template <typename T>
class BinarySearchTree {
 private:
  // private node class
  struct Node {
    T value;
    Node* left;
    Node* right;
    Node(T value) : value(value), left(nullptr), right(nullptr) {}
  };

  Node* root;

  Node* insertRecursive(Node* node, T value) {
    if (node == nullptr) return new Node(value);

    if (value < node->value)
      node->left = insertRecursive(node->left, value);
    else if (value > node->value)
      node->right = insertRecursive(node->right, value);

    return node;
  }

  bool containsRecursive(Node* node, T value) {
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

  void inOrderTraversalRecursive(Node* node) {
    if (node == nullptr) return;

    inOrderTraversalRecursive(node->left);
    std::cout << node->value << " ";
    inOrderTraversalRecursive(node->right);
  }

  Node* findMinNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) current = current->left;
    return current;
  }

 public:
  BinarySearchTree() : root(nullptr) {}
  void insert(T value) { root = insertRecursive(root, value); }
  bool contains(T value) { return containsRecursive(root, value); }
  void remove(T value) { root = removeRecursive(root, value); }
  void inOrderTraversal() {
    inOrderTraversalRecursive(root);
    std::cout << std::endl;
  }
};

#endif  // BST_HPP
