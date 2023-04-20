#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cassert>

using namespace std;


// a fake graph class for testing
// Tree:
// 0 -- 1 -- 4
// |    |
// 3 -- 2
class Graph {
 private:
 public:
  Graph() {};
  vector<int> getAdjacentVertexIDs (int vertexID) const {
    switch (vertexID) {
      case 0:
        return vector<int>{1, 3};
      case 1:
        return vector<int>{0, 2, 4};
      case 2:
        return vector<int>{1, 3};
      case 3:
        return vector<int>{0, 2};
      case 4:
        return vector<int>{1};
    }
    return vector<int>{};
  }
  int getVertexCount() const {
    return 5;
  }
};

// Breadth First Search
vector<int> BFS(const Graph &G, int S) {
  int size = G.getVertexCount();
  vector<bool> visited(size, false);
  queue<int> queue_;
  vector<int> result;
  int currentVertex;

  queue_.push(S);
  visited[S] = true;

  while (!queue_.empty()) {
    currentVertex = queue_.front();
    queue_.pop();
    result.push_back(currentVertex);
    vector<int> neighbors = G.getAdjacentVertexIDs(currentVertex);
    for (int i = 0; i < neighbors.size(); ++i) {
      int vertex = neighbors.at(i);
      if (!visited.at(vertex)) {
        queue_.push(vertex);
        visited.at(vertex) = true;
      }
    }
  }

  return result;
}

vector<int> DFS(const Graph &G, int S) {
  int size = G.getVertexCount();
  vector<bool> visited(size, false);
  stack<int> stack_;
  vector<int> result;
  int currentVertex;

  stack_.push(S);

  while (!stack_.empty()) {
    currentVertex = stack_.top();
    stack_.pop();
      if (!visited.at(currentVertex)) {
        result.push_back(currentVertex);
        visited.at(currentVertex) = true;
        vector<int> neighbors = G.getAdjacentVertexIDs(currentVertex);
        for (int i = 0; i < neighbors.size(); ++i) {
          int vertex = neighbors.at(i);
          stack_.push(vertex);
        }
      }
  }

  return result;
}

// Recursive DFS helper declaration
void recDFS(const Graph &G, int currentVertex, vector<bool> &visitedSet, vector<int> &result);

// Recursive DFS
vector<int> DFS1(const Graph &G, int S) {
  vector<bool> visitedSet(G.getVertexCount(), false);
  vector<int> result;
  recDFS(G, 0, visitedSet, result);
  return result;
}

void recDFS(const Graph &G, int currentVertex, vector<bool> &visitedSet, vector<int> &result) {
  if (!visitedSet.at(currentVertex)) {
    visitedSet.at(currentVertex) = true;
    result.push_back(currentVertex);
    vector<int> neighbors = G.getAdjacentVertexIDs(currentVertex);
    for (int i = 0; i < neighbors.size(); ++i)
      recDFS(G, neighbors.at(i), visitedSet, result);
  }
}


int main() {
  Graph G;
  vector<int> result = BFS(G, 0);
  cout << "BFS: ";
  for (int i:result)
    cout << i << " ";
  cout << endl;

  result = DFS(G, 0);
  cout << "DFS: ";
  for (int i:result)
    cout << i << " ";
  cout << endl;

  result = DFS1(G, 0);
  cout << "DFS: ";
  for (int i:result)
    cout << i << " ";
  cout << endl;

  return 0;
}