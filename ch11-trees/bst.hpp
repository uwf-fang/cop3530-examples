#ifndef BST_HPP
#define BST_HPP

template <class T>
class Node {
  T value;
  Node *left;
  Node *right;
 public:
  Node();
  Node(T value, Node *left, Node *right);
  void setValue(T value);
  T getValue(T);
  void setLeft(Node *left);
  void setRight(Node *right);
  Node * getLeft();
  Node * getRight();
};

template <class T>
class BinSearchTree {
  Node<T> *root;
  Node<T> *searchHelper(Node<T> *root, T value);
  Node<T> *insertHelper(Node<T> *root, T value);
  Node<T> *removeHelper(Node<T> *root, T value);
  void printInOrderHelper(Node<T> *root);
 public:
  BinSearchTree();
  Node<T> *search(T value);
  void insert(T value);
  void remove(T value);
  void printInOrder();
};

template <class T>
Node<T> * BinSearchTree<T>::search(T value) {
  return searchHelper(root, value);
}

template <class T>
Node<T> *BinSearchTree<T>::searchHelper(Node<T> *root, T value) {
  if (root == nullptr)
    return nullptr;
  else if (root->getValue() == value)
    return root;
  else if (root->getValue() > value)
    return searchHelper(root->getLeft(), value);
  else
    return searchHelper(root->getRight(), value);
}


template <class T>
void BinSearchTree<T>::insert(T value) {
  root = insertHelper(root, value);
}

template <class T>
Node<T> *BinSearchTree<T>::insertHelper(Node<T> *root, T value) {
  if (root == nullptr)
    return new Node<T>(value, nullptr, nullptr);
  if (value > root->getValue()) {
    root->setRight(insertHelper(root->getRight(), value));
    return root;
  }
  else {
    root->setLeft(insertHelper(root->getLeft(), value));
    return root;
  }
}

template <class T>
void BinSearchTree<T>::remove(T value) {
  root = removeHelper(root, value);
}

template <class T>
Node<T> *BinSearchTree<T>::removeHelper(Node<T> *root, T value) {
  if (root == nullptr)
    return nullptr;
  if (value < root->getValue())
    root->setLeft(removeHelper(root->getLeft(), value));
  else if (value > root->getValue())
    root->setRight(removeHelper(root->getRight(), value));
  else {  // match the current node
    if (root->getLeft() == nullptr && root->getRight() == nullptr) {
      delete root;
      return nullptr;
    } else if (root->getLeft() == nullptr) { // only have right child
      Node<T> *backup = root->getRight();
      delete root;
      return backup;
    } else if (root->getRight() == nullptr) { // only have left child
      Node<T> *backup = root->getLeft();
      delete root;
      return backup;
    } else {   // two children
        // find the left most node in the right subtree
        Node<T> * current = root->getRight();
        while (current->getLeft() != nullptr)
          current = current->getLeft();
        root->setValue(current->getValue());
        root->setRight(removeHelper(root->getRight(), root->getValue()))
    }
  }
}

template <class T>
void BinSearchTree<T>::printInOrder() {
  printInOrderHelper(root);
}

template <class T>
void BinSearchTree<T>::printInOrderHelper(Node<T> *root) {
  if (root != nullptr) {
    printInOrderHelper(root->getLeft());
    cout << root->getValue << " ";
    printInOrderHelper(root->getRight());
  }
}

#endif
