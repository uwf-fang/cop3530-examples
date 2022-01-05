#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>  // vector
#include <string>
#include <list>   // linked list

// Assuming each vertex has a unique label
// Assuming you know the number of vertices
// Undirected graph
// positive int weights
class GraphAdjList {
 private:

  // 1st option
  // adjacencyList can be C array of pointers to linked list nodes
  // std::vector<std::string> vertices;
  // ListNode **adjacencyList;

  // 2nd Option to store labels together
  // std::vector<std::pair<std::string, std::vector<std::pair<int, int>>>> adjacencyList;

  // 3rd option

  // The index of each label in this vector will be referred to as the ID
  //   of the vertex.
  std::vector<std::string> vertices;

  // the first element in the pair is the id of the dest vertex
  // the second element in the pair is the weight
  std::vector<std::vector<std::pair<int, int>>> adjacencyList;

  bool isValidID(int id) const;
 public:
  GraphAdjList(int numOfVertices = 0);
  bool registerVertices(const std::vector<std::string> &labels);
  bool registerEdge(int id1, int id2, int weight);
  int getNumVertices() const;
  int getId(std::string label) const;
  int getWeight(int id1, int id2) const;
  const std::vector<std::string> &getVertices() const;
  // std::vector<int> getNeighbors(int id) const;
  // std::vector<std::string> DFS(std::string label) const;
  // std::vector<std::string> BFS(std::string label) const;
};

// Assuming each vertex has a unique label
// Assuming you know the number of vertices
// positive weights
class GraphAdjMatrix {
 private:
  std::vector<std::string> vertices;
  // Can also be simply 2D dynamic int array
  // int **adjacencyMatrix;
  std::vector<std::vector<int>> adjacencyMatrix;
 public:
};

#endif // GRAPH_HPP_