#include <iostream>
#include <vector>
using namespace std;

#define	INFINITE	1024
#define NODES 5

class dijkstra {
  
public:
  
  // vectors
  vector<int> visited;
  vector<int> notvisited;

  //Variables
  int G[NODES][NODES];
  int dist[NODES]; 
  int prec[NODES];
  
  //functions
  void sort(vector<int>* v);
  void update(vector<int>* v, int pos);
  void printpath(int v);
  void print();
  void initialize();

  dijkstra() {
  }
};

void dijkstra::printpath(int node) {
  
  vector<int> path;

  int curr = prec[node];
  while (curr != -1) {
    //    cout << curr << " to ";
    path.push_back(curr);
    curr = prec[curr];
  }
  
  cout << "Shortest path from 0 to node " << node << " is " << dist[node] << endl;
  cout << "Path is :\t";

  for(int i = 0 ; i < path.size(); i++) {
    if(path.size() == 0)
      break;
    cout << path.at(path.size() - i - 1 );
    cout << "->";
  }
  cout << node ;
  cout << endl << endl;
}

void dijkstra::print() {
  cout << "\t";
  for(int i = 0; i < NODES; i++) {
    cout << "node " << i << "\t";
  }
  cout << endl << endl;

  for( int i = 0; i < NODES; i++) {
    cout << "node " << i << "\t";
    for( int j = 0; j < NODES; j++) {
      if(i == j)
	cout << "0\t";
      else if(G[i][j] == INFINITE)
	cout << "INF\t";
      else
	cout << G[i][j] << "\t";
    }
    cout << endl;
  }
}

void dijkstra::update(vector<int>* v, int pos) {
  for (int i = 0; i < v->size(); i++) {
    int vi = v->at(i);
    if (G[pos][vi] == INFINITE)
      continue;
    if (dist[vi] > dist[pos] + G[pos][vi]) {
      dist[vi] = dist[pos] + G[pos][vi];
      prec[vi] = pos;
    }
  }
}

void dijkstra::sort(vector<int>* v) {
  for (unsigned int i = 0; i < v->size(); i++)
    for (unsigned int j = i; j < v->size(); j++)
      if (dist[v->at(i)] > dist[v->at(j)]) {
	int swp = v->at(i);
	v->at(i) = v->at(j);
	v->at(j) = swp;
      }
}


void dijkstra::initialize() {
  for (int i = 0; i < NODES; i++)
    for (int j = 0; j < NODES; j++)
      G[i][j] = INFINITE;
  
  //  G[0][1] = 60;
  //  G[0][2] = 10;
  G[1][3] = 90;
  G[0][4] = 20;
  G[2][3] = 30;
  G[4][2] = 20;
  G[4][3] = 10;
  G[4][1] = 90;
 
  for (int i = 0; i < NODES; i++) {
    notvisited.push_back(i);
    dist[i] = INFINITE;
    prec[i] = -1;
  }
  dist[0] = 0; 
  sort(&notvisited); 

}
 
int main() {
  
  dijkstra obj;

  obj.initialize();
  obj.print();

  while (obj.notvisited.size() > 0) {
    int curr = obj.notvisited.front();

    //Pop operation
    for (int i = 0; i < obj.notvisited.size() - 1; i++) {
      obj.notvisited.at(i) = obj.notvisited.at(i + 1);
    }

    obj.notvisited.pop_back();
    obj.visited.push_back(curr);
    obj.update(&obj.notvisited, curr);
    obj.sort(&obj.notvisited); 
  }

  for(int i =0; i < NODES; i++) {
    obj.printpath(i);
  }
  return 0;
}
