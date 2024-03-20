#include "bst.hpp"
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void testBST() {
  cout << "Testing binary search tree..." << endl;
  BinarySearchTree<int> tree;

  cout << "Testing add and traversal" << endl;
  tree.insert(5);
  assert((vector<int>{5} == tree.inOrderTraversal()));


  tree.insert(6);
  assert((vector<int>{5, 6} == tree.inOrderTraversal()));

  assert(tree.contains(5));
  assert(tree.contains(6));

  tree.remove(5);
  assert((vector<int>{6} == tree.inOrderTraversal()));
  assert(!tree.contains(5));
  assert(tree.contains(6));

  tree.insert(9);
  tree.insert(7);
  tree.insert(8);
  assert((vector<int>{6, 7, 8, 9} == tree.inOrderTraversalIterative()));

  cout << "Testing big three" << endl;
  BinarySearchTree<int> tree2 = tree;
  assert((vector<int>{6, 7, 8, 9} == tree2.inOrderTraversal()));

  BinarySearchTree<int> tree3;
  tree3 = tree;
  assert((vector<int>{6, 7, 8, 9} == tree3.inOrderTraversal()));

  cout << "All tests passed!" << endl;
}

int main()
{
  testBST();

  return EXIT_SUCCESS;
}
