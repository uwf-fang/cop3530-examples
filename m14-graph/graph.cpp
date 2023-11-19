#include "graph.hpp"

#include <iostream>

using namespace std;

GraphAdjListVector::GraphAdjListVector(int numOfVertices) {
  vertices.resize(numOfVertices);
  adjacencyList.resize(numOfVertices);
}

bool GraphAdjListVector::isValidID(int id) const {
  return id >= 0 || id < vertices.size();
}

bool GraphAdjListVector::registerVertices(const vector<string> &labels) {
  if (!vertices.empty() && vertices.size() != labels.size()) return false;
  adjacencyList.clear();
  vertices = labels;
  adjacencyList.resize(labels.size());
  return true;
}

bool GraphAdjListVector::registerEdge(int id1, int id2, int weight) {
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

int GraphAdjListVector::getNumVertices() const { return vertices.size(); }

int GraphAdjListVector::getId(string label) const {
  int size = getNumVertices();
  for (int i = 0; i < size; ++i)
    if (vertices.at(i) == label) return i;
  return -1;
}

int GraphAdjListVector::getWeight(int id1, int id2) const {
  auto &list1 = adjacencyList.at(id1);
  int size = list1.size();
  for (int i = 0; i < size; ++i)
    if (list1.at(i).first == id2) return list1.at(i).second;
  return -1;
}

vector<int> GraphAdjListVector::getNeighbors(int id) const {
  vector<int> neighbors;
  auto &list = adjacencyList.at(id);
  for (int i = 0; i < list.size(); ++i) neighbors.push_back(list.at(i).first);
  return neighbors;
}

GraphAdjListArray::~GraphAdjListArray() {
  node *temp;
  for (int i = 0; i < size; ++i) {
    node *head = adjList[i];
    while (head != nullptr) {
      temp = head;
      head = head->next;
      delete temp;
    }
  }
  delete[] adjList;
  delete[] vertices;
}

bool GraphAdjListArray::registerVertices(
    const std::vector<std::string> &labels) {
  size = labels.size();
  vertices = new std::string[size];
  for (int i = 0; i < size; ++i) vertices[i] = labels.at(i);
  adjList = new node *[size];
  for (int i = 0; i < size; ++i) adjList[i] = nullptr;
}

bool GraphAdjListArray::registerEdge(int id1, int id2, int weight) {
  node *head = adjList[id1];
  head = new node(id2, weight, head);
  head = adjList[id2];
  head = new node(id1, weight, head);
}
vector<int> GraphAdjListArray::getNeighbors(int id) const {
  std::vector<int> result;
  node *head = adjList[id];
  while (head != nullptr) {
    result.push_back(head->destID);
    head = head->next;
  }
  return result;
}
