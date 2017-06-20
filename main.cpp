#include "Test.h"
#include <iostream>
#include <limits>
#include <stdexcept>
using namespace std;

int* getShortestPath(int** graph, int size, int origin)
{
  int* predecessor = new int[size];
  int* distance = new int[size];
  for (int i = 0; i < size; ++i)
  {
    predecessor[i] = -1;
    distance[i] = std::numeric_limits<int>::max();
  }
  predecessor[origin] = 0;
  distance[origin] = 0;

  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      if(graph[i][j]!=-1 && (distance[i] + graph[i][j] < distance[j]))
      {
        distance[j] = distance[i] + graph[i][j];
        predecessor[j] = i;
      }
    }
  }

  //Checking negative cycles
  /*for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      if(distance[i] + graph[i][j] < distance[j]){
        throw std::invalid_argument( "Grapsh contains a negative-weight cycle.");
      }
    }
  }*/

  /*
  for each edge (u, v) with weight w in edges:
         if distance[u] + w < distance[v]:
             error "Graph contains a negative-weight cycle"
  */
  return predecessor;
}

int main ()
{
    test();
    return 0;
}
