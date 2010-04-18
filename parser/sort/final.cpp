#include <iostream>
#include <vector>
using namespace std;

#define	INFINITE	1024
const int NODES = 5;
int G[NODES][NODES];
int dist[NODES]; 
int prec[NODES];
vector<int> visited;
vector<int> notvisited;

void sort(vector<int>* v) {
    for (unsigned int i = 0; i < v->size(); i++)
        for (unsigned int j = i; j < v->size(); j++)
            if (dist[v->at(i)] > dist[v->at(j)]) {
                int temp = v->at(i);
                v->at(i) = v->at(j);
                v->at(j) = temp;
            }
}
 
void update(vector<int>* v, int u) {
    for (unsigned int i = 0; i < v->size(); i++) {
        int vi = v->at(i);
        if (G[u][vi] == INFINITE)
            continue;
        if (dist[vi] > dist[u] + G[u][vi]) {
            dist[vi] = dist[u] + G[u][vi];
            prec[vi] = u;
        }
    }
}

void ShortestPath(int v) {
    cout << "Distance to " << v << " is " << dist[v] << endl;
    cout << "Shortest path: ";
    int x = prec[v];
    while (x != -1) {
        cout << x << "<-";
        x = prec[x];
    }
    cout << endl << endl;
}
 
int main() {
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
        notvisited.push_back(i);
        dist[i] = INFINITE;
        prec[i] = -1;
    }
    dist[0] = 0; 
    sort(&notvisited); 
 
    while (notvisited.size() > 0) {
        int x = notvisited.front();
        for (unsigned int i = 0; i < notvisited.size() - 1; i++) {
            notvisited.at(i) = notvisited.at(i + 1);
        }
        notvisited.pop_back();
        visited.push_back(x);
        update(&notvisited, x);
        sort(&notvisited); 
    }
 
    ShortestPath(4);
    return 0;
}
