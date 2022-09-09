#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cassert>

using namespace std;

// a fake graph class for testing only
class Graph {
 private:
 public:
  Graph() {};
  std::vector<int> getAdjacentVertexIDs (int vertexID) {
    switch (vertexID) {
      case 0:
        return vector<int>{1, 3};
      case 1:
        return vector<int>{0};
      case 2:
        return vector<int>{3};
      case 3:
        return vector<int>{0, 2};
    }
    return vector<int>{};
  }
  int getVertexCount() {
    return 4;
  }
};

vector<int> BFS(Graph G, int S) {
  int size = G.getVertexCount();
  vector<bool> visited(size, false);
  list<int> queue;
  vector<int> result;
  int currentVertex;

  queue.push_front(S);
  visited[S] = true;

  while (!queue.empty()) {
    currentVertex = queue.back();
    queue.pop_back();
    result.push_back(currentVertex);
    vector<int> neighbors = G.getAdjacentVertexIDs(currentVertex);
    for (int i = 0; i < neighbors.size(); ++i) {
      int vertex = neighbors.at(i);
      if (!visited.at(vertex)) {
        queue.push_front(vertex);
        visited.at(currentVertex) = true;
      }
    }
  }

  return result;
}

int main() {
  Graph G;
  vector<int> result = BFS(G, 0);
  for (int i:result)
    cout << i << " ";

  return 0;
}