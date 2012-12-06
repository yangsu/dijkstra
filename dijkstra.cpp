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

#define O 0
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define T 7

int main() {
  char numToLabel[] = {'O', 'A', 'B', 'C', 'D', 'E', 'F', 'T'};
  int count = sizeof(numToLabel)/sizeof(char);

  AdjacencyList adjacencyList(count);

  adjacencyList[O].push_back(Neighbor(A, 2));
  adjacencyList[O].push_back(Neighbor(B, 5));
  adjacencyList[O].push_back(Neighbor(C, 4));

  adjacencyList[A].push_back(Neighbor(O, 2));
  adjacencyList[A].push_back(Neighbor(B, 2));
  adjacencyList[A].push_back(Neighbor(D, 7));
  adjacencyList[A].push_back(Neighbor(F, 12));

  adjacencyList[B].push_back(Neighbor(A, 2));
  adjacencyList[B].push_back(Neighbor(O, 5));
  adjacencyList[B].push_back(Neighbor(C, 1));
  adjacencyList[B].push_back(Neighbor(E, 3));
  adjacencyList[B].push_back(Neighbor(D, 4));

  adjacencyList[C].push_back(Neighbor(O, 4));
  adjacencyList[C].push_back(Neighbor(B, 1));
  adjacencyList[C].push_back(Neighbor(E, 4));

  adjacencyList[D].push_back(Neighbor(A, 7));
  adjacencyList[D].push_back(Neighbor(B, 4));
  adjacencyList[D].push_back(Neighbor(E, 1));
  adjacencyList[D].push_back(Neighbor(T, 5));

  adjacencyList[E].push_back(Neighbor(B, 3));
  adjacencyList[E].push_back(Neighbor(C, 4));
  adjacencyList[E].push_back(Neighbor(D, 1));
  adjacencyList[E].push_back(Neighbor(T, 7));

  adjacencyList[F].push_back(Neighbor(A, 12));
  adjacencyList[F].push_back(Neighbor(T, 3));

  adjacencyList[T].push_back(Neighbor(F, 3));
  adjacencyList[T].push_back(Neighbor(D, 5));
  adjacencyList[T].push_back(Neighbor(E, 7));

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