#include "graph.hpp"
#include <iostream>

using namespace std;

GraphAdjList::GraphAdjList(int numOfVertices) {
  vertices.resize(numOfVertices);
  adjacencyList.resize(numOfVertices);
}

bool GraphAdjList::isValidID(int id) const {
  return id >= 0 || id < vertices.size();
}

bool GraphAdjList::registerVertices(const vector<string> &labels) {
  if (!vertices.empty() && vertices.size() != labels.size())
    return false;
  adjacencyList.clear();
  vertices = labels;
  adjacencyList.resize(labels.size());
  return true;
}

bool GraphAdjList::registerEdge(int id1, int id2, int weight) {
  if (!isValidID(id1) || !isValidID(id2)) return false;
  auto &list1 = adjacencyList.at(id1);
  auto &list2 = adjacencyList.at(id2);
  if (getWeight(id1, id2) == -1) {
    list1.push_back(pair<int, int>(id2, weight));
    list2.push_back(pair<int, int>(id1, weight));
    return true;
  } else  // edge already exist
    return false;
}

int GraphAdjList::getNumVertices() const { return vertices.size(); }

int GraphAdjList::getId(string label) const {
  int size = getNumVertices();
  for (int i = 0; i < size; ++i)
    if (vertices.at(i) == label) return i;
  return -1;
}

int GraphAdjList::getWeight(int id1, int id2) const {
  auto &list1 = adjacencyList.at(id1);
  int size = list1.size();
  for (int i = 0; i < size; ++i)
    if (list1.at(i).first == id2) return list1.at(i).second;
  return -1;
}
const vector<string> &GraphAdjList::getVertices() const { return vertices; }
