//print the number of paths and the paths present between source and destination node in a graph

#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;
public:
    vector<vector<int> > paths;
    void printAllPathsUtil(int, int, bool[], int[], int&);
    Graph(int V);
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::printAllPaths(int s, int d) {
    bool *visited = new bool[V];
    int *path = new int[V];
    int path_index = 0;
    for (int i = 0; i < V; i++)
        visited[i] = false;
    printAllPathsUtil(s, d, visited, path, path_index);
}

void Graph::printAllPathsUtil(int u, int d, bool visited[], int path[], int &path_index) {
    visited[u] = true;
    path[path_index] = u;
    path_index++;
    if (u == d) {
        vector<int> temp;
        for (int i = 0; i < path_index; i++) {
            temp.push_back(path[i]);
        }
        paths.push_back(temp);
    } else {
        for (int i = 0; i < adj[u].size(); i++) {
            if (!visited[adj[u][i]]) {
                printAllPathsUtil(adj[u][i], d, visited, path, path_index);
            }
        }
    }
    path_index--;
    visited[u] = false;
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
    int s = 2, d = 3;
    g.printAllPaths(s, d);
    cout << "Number of paths between " << s << " and " << d << " is " << g.paths.size() << endl;
    cout << "Paths are: " << endl;
    for (int i = 0; i < g.paths.size(); i++) {
        for (int j = 0; j < g.paths[i].size(); j++) {
            cout << g.paths[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

