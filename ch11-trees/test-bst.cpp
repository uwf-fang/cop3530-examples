#include "bst.hpp"
#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

void testBST() {
  cout << "Testing binary search tree..." << endl;
  BinarySearchTree<int> tree;

  // redirect cout
  streambuf *old = cout.rdbuf();
  ostringstream outSS;
  cout.rdbuf(outSS.rdbuf());

  tree.insert(5);
  tree.inOrderTraversal();
  assert(outSS.str() == "5 \n");

  tree.insert(6);
  outSS.str("");
  tree.inOrderTraversal();
  assert(outSS.str() == "5 6 \n");

  assert(tree.contains(5));
  assert(tree.contains(6));

  tree.remove(5);
  outSS.str("");
  tree.inOrderTraversal();
  assert(outSS.str() == "6 \n");
  assert(!tree.contains(5));
  assert(tree.contains(6));

  // restore cout
  cout.rdbuf(old);

  cout << "All tests passed!" << endl;
}

int main(int argc, char const *argv[])
{
  testBST();
  return 0;
}
