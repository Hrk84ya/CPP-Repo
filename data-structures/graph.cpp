#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adjList;
    
public:
    Graph(int v) : vertices(v), adjList(v) {}
    
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // For undirected graph
    }
    
    void addDirectedEdge(int u, int v) {
        adjList[u].push_back(v);
    }
    
    void printGraph() {
        std::cout << "Graph adjacency list:\n";
        for (int i = 0; i < vertices; ++i) {
            std::cout << i << ": ";
            for (int neighbor : adjList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << "\n";
        }
    }
    
    void BFS(int start) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;
        
        visited[start] = true;
        q.push(start);
        
        std::cout << "BFS traversal starting from " << start << ": ";
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            std::cout << current << " ";
            
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << "\n";
    }
    
    void DFSUtil(int vertex, std::vector<bool>& visited) {
        visited[vertex] = true;
        std::cout << vertex << " ";
        
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
    
    void DFS(int start) {
        std::vector<bool> visited(vertices, false);
        std::cout << "DFS traversal starting from " << start << ": ";
        DFSUtil(start, visited);
        std::cout << "\n";
    }
    
    void DFSIterative(int start) {
        std::vector<bool> visited(vertices, false);
        std::stack<int> s;
        
        s.push(start);
        
        std::cout << "DFS iterative traversal starting from " << start << ": ";
        
        while (!s.empty()) {
            int current = s.top();
            s.pop();
            
            if (!visited[current]) {
                visited[current] = true;
                std::cout << current << " ";
                
                // Add neighbors to stack (in reverse order for consistent output)
                for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
                    }
                }
            }
        }
        std::cout << "\n";
    }
    
    bool hasPath(int start, int end) {
        if (start == end) return true;
        
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;
        
        visited[start] = true;
        q.push(start);
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (int neighbor : adjList[current]) {
                if (neighbor == end) return true;
                
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
    
    void findAllPaths(int start, int end, std::vector<int>& path, std::vector<bool>& visited) {
        visited[start] = true;
        path.push_back(start);
        
        if (start == end) {
            std::cout << "Path: ";
            for (int vertex : path) {
                std::cout << vertex << " ";
            }
            std::cout << "\n";
        } else {
            for (int neighbor : adjList[start]) {
                if (!visited[neighbor]) {
                    findAllPaths(neighbor, end, path, visited);
                }
            }
        }
        
        path.pop_back();
        visited[start] = false;
    }
    
    void printAllPaths(int start, int end) {
        std::vector<bool> visited(vertices, false);
        std::vector<int> path;
        
        std::cout << "All paths from " << start << " to " << end << ":\n";
        findAllPaths(start, end, path, visited);
    }
};

// Weighted graph for shortest path algorithms
class WeightedGraph {
private:
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjList;  // {neighbor, weight}
    
public:
    WeightedGraph(int v) : vertices(v), adjList(v) {}
    
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});  // For undirected graph
    }
    
    void dijkstra(int start) {
        std::vector<int> dist(vertices, INT_MAX);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        
        dist[start] = 0;
        pq.push({0, start});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            for (auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        std::cout << "Shortest distances from vertex " << start << ":\n";
        for (int i = 0; i < vertices; ++i) {
            std::cout << "To " << i << ": " << (dist[i] == INT_MAX ? -1 : dist[i]) << "\n";
        }
    }
};

int main() {
    // Unweighted graph example
    std::cout << "=== Unweighted Graph ===\n";
    Graph g(6);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    
    g.printGraph();
    std::cout << "\n";
    
    g.BFS(0);
    g.DFS(0);
    g.DFSIterative(0);
    
    std::cout << "\nPath exists from 0 to 5: " << (g.hasPath(0, 5) ? "Yes" : "No") << "\n";
    std::cout << "Path exists from 0 to 6: " << (g.hasPath(0, 6) ? "Yes" : "No") << "\n";
    
    std::cout << "\n";
    g.printAllPaths(0, 5);
    
    // Weighted graph example
    std::cout << "\n=== Weighted Graph (Dijkstra's Algorithm) ===\n";
    WeightedGraph wg(5);
    
    wg.addEdge(0, 1, 4);
    wg.addEdge(0, 2, 1);
    wg.addEdge(1, 3, 1);
    wg.addEdge(2, 1, 2);
    wg.addEdge(2, 3, 5);
    wg.addEdge(3, 4, 3);
    
    wg.dijkstra(0);
    
    return 0;
}