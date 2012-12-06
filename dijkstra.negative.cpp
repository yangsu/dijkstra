#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <utility>
#include <iterator>
#include <cfloat>

using namespace std;

typedef int Vertex;

struct Neighbor {
  Vertex target;
  float weight;
  Neighbor(Vertex t, float w) : target(t), weight(w) {}
};

typedef vector<vector<Neighbor> > AdjacencyList;
typedef vector<Neighbor>::const_iterator NeighborIterator;

void dijkstra(Vertex source, const AdjacencyList &adjacencyList, vector<float> &minWeights, vector<Vertex> &previous ) {
  int n = adjacencyList.size();

  minWeights.clear();
  minWeights.resize(n, FLT_MAX);
  minWeights[source] = 0;

  previous.clear();
  previous.resize(n, -1);

  set<pair<float, Vertex> > vertexQ;
  vertexQ.insert(make_pair(minWeights[source], source));

  while (!vertexQ.empty()) {
    float dist = vertexQ.begin()->first;
    Vertex u = vertexQ.begin()->second;
    vertexQ.erase(vertexQ.begin());

    // Visit each edge exiting u
    const vector<Neighbor> &neighbors = adjacencyList[u];
    for (
      NeighborIterator neighborIter = neighbors.begin();
      neighborIter != neighbors.end();
      neighborIter++
    ) {
      Vertex v = neighborIter->target;
      float currentWeight = dist + neighborIter->weight;

      if (currentWeight < minWeights[v]) {
        vertexQ.erase(make_pair(minWeights[v], v));

        minWeights[v] = currentWeight;
        previous[v] = u;
        vertexQ.insert(make_pair(minWeights[v], v));
      }
    }
  }
}


list<Vertex> computeShortestPaths(Vertex vertex, const vector<Vertex> &previous) {
  list<Vertex> path;
  for ( ; vertex != -1; vertex = previous[vertex])
    path.push_front(vertex);
  return path;
}

#define A 0
#define B 1
#define C 2
#define D 3

int main() {
  char numToLabel[] = {'A', 'B', 'C', 'D'};
  int count = sizeof(numToLabel)/sizeof(char);

  AdjacencyList adjacencyList(count);

  adjacencyList[A].push_back(Neighbor(B, 1));
  adjacencyList[A].push_back(Neighbor(D, 99));
  adjacencyList[A].push_back(Neighbor(C, 0));

  adjacencyList[B].push_back(Neighbor(C, 1));

  adjacencyList[D].push_back(Neighbor(B, -300));

  vector<float> minWeights;
  vector<Vertex> previous;

  dijkstra(0, adjacencyList, minWeights, previous);

  for (int i = A; i < count; ++i) {
    Vertex curr = i;
    cout << "Shortest path to " << numToLabel[curr] << " : [ ";
    list<Vertex> path = computeShortestPaths(curr, previous);
    for (list<Vertex>::iterator it = path.begin(); it != path.end(); it++) {
      cout << numToLabel[*it] << " ";
    }
    cout << "]\tCost: " << minWeights[curr] << endl;
  }
  return 0;
}