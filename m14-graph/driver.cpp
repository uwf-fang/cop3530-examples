#include "graph.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findMinVertex(vector<int> &distances, vector<bool> &visited);
vector<int> shortestPaths(GraphAdjList &graph, string srcLabel);

int main() {
  GraphAdjList graph;
  // initiate the graph
  graph.registerVertices(vector<string>{"A", "B", "C", "D"});
  graph.registerEdge(0, 1, 3);
  graph.registerEdge(1, 2, 1);
  graph.registerEdge(0, 3, 5);
  graph.registerEdge(2, 3, 1);
  cout << "Initialization done\n";

  vector<int> distances = shortestPaths(graph, "A");
  for (int dist: distances)
    cout << dist << " ";
  cout << endl;
  return EXIT_SUCCESS;
}

int findMinVertex(vector<int> &distances, vector<bool> &visited) {
  int min = INT_MAX;
  int minIndex = 0;
  int numVertices = distances.size();

  for (int i = 0; i < numVertices; i++)
    if (!visited.at(i) && distances.at(i) <= min) {
      min = distances.at(i);
      minIndex = i;
    }
  return minIndex;
}


vector<int> shortestPaths(GraphAdjList &graph, string srcLabel) {
  int numVertices = graph.getNumVertices();
  vector<int> distances(numVertices, INT_MAX);
  vector<bool> visited(numVertices, false);

  int srcID = graph.getId(srcLabel);
  distances.at(srcID) = 0;

  for (int i = 0; i < numVertices - 1; i++) {
    cout << "Round " << (i + 1) << endl;
    int v = findMinVertex(distances, visited);
    visited.at(v) = true;
    for (int j = 0; j < numVertices; j++)
      if (!visited.at(j) &&
          graph.getWeight(v, j) != -1 &&
          distances.at(v) != INT_MAX &&
          distances.at(v) + graph.getWeight(v, j) < distances.at(j))
        {
          distances.at(j) = distances.at(v) + graph.getWeight(v, j);
        }
  }

  return distances;
}
