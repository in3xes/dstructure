#include <iostream>
#include <vector>

using namespace std;

#define	INFINITE 1024 
const int NODES = 5;
int G[NODES][NODES];
int distance[NODES]; 
int prec[NODES];
vector<int> visited;
vector<int> notvisited;
 
void sort(vector<int>* v) {
  for (unsigned int i = 0; i < v->size(); i++)
    for (unsigned int j = i; j < v->size(); j++)
      if (distance[v->at(i)] > distance[v->at(j)]) {
	int t = v->at(i);
	v->at(i) = v->at(j);
	v->at(j) = t;
      }
}
 
void update(vector<int>* v, int pos) {
  for (unsigned int i = 0; i < v->size(); i++) {
    int vi = v->at(i);
    if (G[pos][vi] == INFINITE)
      continue;
    if (distance[vi] > distance[pos] + G[pos][vi]) {
      distance[vi] = distance[pos] + G[pos][vi];
      prec[vi] = u;
    }
  }
}

void printShortestPathTo(int pos) {
  cout << "Distance to " << pos << " is " << distance[pos] << endl;
  cout << "Shortest path: ";
  int x = prec[pos];
  while (x != -1) {
    cout << x << "<-";
    x = prec[x];
  }
  cout << endl << endl;
}
 
int main() {
  //initialize all the costs in the graph
  for (int i = 0; i < NODES; i++)
    for (int j = 0; j < NODES; j++)
      G[i][j] = INFINITE;
 
  G[0][1] = 20;
  G[0][4] = 40;
  G[1][4] = 50;
  G[2][3] = 30;
  G[2][4] = 60;
  G[4][2] = 20;
  G[4][3] = 100;
 
  for (int i = 0; i < NODES; i++) {
    for (int j = 0; j < NODES; j++) {
      cout << G[i][j] << "\t";
    }
    cout << endl;
  }
  for (int i = 0; i < NODES; i++) {
    notvisited.push_back(i);//initialize all the variables
    distance[i] = INFINITE;//all distances to infinite
    prec[i] = -1;//nodes have no predecesors 
  }
  distance[0] = 0; //the distance of the source is 0
  sort(&notvisited); //we sort the nodes according to the distance
 
  while (notvisited.size() > 0) {
    int x = notvisited.front();//take the node with the shortest distance
    for (unsigned int i = 0; i < notvisited.size() - 1; i++) {
      notvisited.at(i) = notvisited.at(i + 1);
    }
    cout << endl;
    notvisited.pop_back();
    visited.push_back(x);//mark it as visited
    relax(&notvisited, x);//update the distances
    sort(&notvisited); //sort the nodes according to the new distances
    for(int i = 0; i < notvisited.size(); i++) {
      cout << notvisited.at(i) << "\t" ;
    }
  }
  for(int i = 0; i < 5; i++) {
  printShortestPathTo(i);//choose any node
  cout << prec[i] << endl;
  cout << distance[i] << endl;
  }
  
  return 0;
}
