#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cassert>

using namespace std;

class Node {
 private:
  int data;
  Node* left;
  Node* right;
 public:
  Node(int value, Node* left = nullptr, Node* right = nullptr) {
    data = value;
    this->left = left;
    this->right = right;
  }
  int getData() {return data;};
  Node* getLeft() {return left;};
  void setLeft(Node* left) {this->left = left;}
  Node* getRight() {return right;}
  void setRight(Node* right) {this->right = right;}
};

class BST {
 private:
  Node *root;
  void deleteSubtree(Node *root) {
    if (root == nullptr)
      return;
    deleteSubtree(root->getLeft());
    deleteSubtree(root->getRight());
    delete root;
    root = nullptr;
  }
  void printSubtree(Node *root) {
    if (root == nullptr)
      return;
    printSubtree(root->getLeft());
    cout << root->getData() << " ";
    printSubtree(root->getRight());
  }
 public:
  BST(Node *root = nullptr) {
    this->root = root;
  }
  void insert(int value) {
    if (root == nullptr)  // empty tree
      root = new Node(value);
    else {
      Node *current = root;
      while (current != nullptr) {
        if (value < current->getData()) // insert to left
          if (current->getLeft() == nullptr) {
            current->setLeft(new Node(value));
            return;
          }
          else
            current = current->getLeft();
        else  // insert to right
          if (current->getRight() == nullptr) {
            current->setRight(new Node(value));
            return;
          }
          else
            current = current->getRight();
      }
    }
  }
  bool search(int value) {
    Node *current = root;
    while (current != nullptr) {
      if (value == current->getData())
        return true;
      else if (value < current->getData())
        current = current->getLeft();
      else
        current = current->getRight();
    }
    return false;
  }
  ~BST() {
    deleteSubtree(root);
  }
  void printInOrder() {
    printSubtree(root);
    cout << endl;
  }
};

int main() {
  BST bst;
  bst.insert(1);
  bst.insert(3);
  bst.insert(2);
  bst.printInOrder();
  assert(bst.search(1));
  assert(bst.search(2));
  assert(!bst.search(5));

  return 0;
}
