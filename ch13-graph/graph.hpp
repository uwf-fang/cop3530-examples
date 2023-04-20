#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>  // vector
#include <string>

// Assuming each vertex has a unique string label
// Assuming you know the number of vertices
// Undirected graph
// positive int weights
class GraphAdjListVector {
 private:
  // The index of each label in this vector will be referred to as the ID
  //   of the vertex.
  std::vector<std::string> vertices;

  // the first element in the pair is the id of the dest vertex
  // the second element in the pair is the weight
  std::vector<std::vector<std::pair<int, int>>> adjacencyList;

  bool isValidID(int id) const;
 public:
  GraphAdjListVector(int numOfVertices = 0);
  bool registerVertices(const std::vector<std::string> &labels);
  bool registerEdge(int id1, int id2, int weight);
  int getNumVertices() const;
  int getId(std::string label) const;
  int getWeight(int id1, int id2) const;
  const std::vector<std::string> &getVertices() const;
  std::vector<int> getNeighbors(int id) const;
};

// Assuming each vertex has a unique string label
// Assuming you know the number of vertices
// Undirected graph
// positive int weights
class GraphAdjListArray {
  struct node {
    int destID;
    int weight;
    node *next;
    node(int destID, int weight, node *next): destID(destID), weight(weight), next(next) {}
  };
  int size;
  std::string *vertices;
  node **adjList;
 public:
  GraphAdjListArray(): size(0), vertices(nullptr), adjList(nullptr) {}
  ~GraphAdjListArray();
  bool registerVertices(const std::vector<std::string> &labels);
  bool registerEdge(int id1, int id2, int weight);
  std::vector<int> getNeighbors(int id) const;
};

// Assuming each vertex has a unique string label
// Assuming you know the number of vertices
// positive weights
class GraphAdjMatrixVector {
 private:
  std::vector<std::string> vertices;
  std::vector<std::vector<int>> adjacencyMatrix;
 public:
  GraphAdjMatrixVector(int numOfVertices = 0);
  bool registerVertices(const std::vector<std::string> &labels);
  bool registerEdge(int id1, int id2, int weight);
  int getNumVertices() const;
  int getId(std::string label) const;
  int getWeight(int id1, int id2) const;
  const std::vector<std::string> &getVertices() const;
};

class GraphAdjMatrixArray {
 private:
  std::string * vertices;
  int **adjacencyMatrix;
 public:
  GraphAdjMatrixArray(int numOfVertices = 0);
  ~GraphAdjMatrixArray();
  bool registerVertices(const std::vector<std::string> &labels);
  bool registerEdge(int id1, int id2, int weight);
  int getNumVertices() const;
  int getId(std::string label) const;
  int getWeight(int id1, int id2) const;
  const std::vector<std::string> &getVertices() const;
};
#endif // GRAPH_HPP_