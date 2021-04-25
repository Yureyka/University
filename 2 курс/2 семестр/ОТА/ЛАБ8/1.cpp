#include <iostream>
#include <cstring>

using namespace std;

#define INF 9999999
#define V 9

int G[V][V] = {
    {0, 2, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 7, 2, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 2, 3, 0, 6, 0},
    {0, 0, 3, 0, 0, 0, 8, 0, 0},
    {0, 0, 0, 0, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 3, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 0, 10},
    {0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int main () {
  int no_edge;
  int selected[V];
  memset (selected, false, sizeof (selected));
  no_edge = 0;
  selected[0] = true;
  int x;
  int y;
  cout << "Edge" << " : " << "Weight";
  cout << endl;
  while (no_edge < V - 1) {
      int min = INF;
      x = 0;
      y = 0;
      for (int i = 0; i < V; i++) {
        if (selected[i]) {
            for (int j = 0; j < V; j++) {
              if (!selected[j] && G[i][j]) { // not in selected and there is an edge
                  if (min > G[i][j]) {
                      min = G[i][j];
                      x = i;
                      y = j;
                  }
              }
          }
        }
      }
      cout << x <<  " - " << y << " :  " << G[x][y];
      cout << endl;
      selected[y] = true;
      no_edge++;
    }
  return 0;
}
