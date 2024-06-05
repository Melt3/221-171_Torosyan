#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

void dijkstra(int start, int n, const vector<vector<Edge>>& graph, vector<int>& dist) {
    dist.assign(n, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d != dist[u]) continue;
        
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, s, f;
    cin >> n >> s >> f;
    s--; f--;  // индексация с 0
    
    vector<vector<Edge>> graph(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int weight;
            cin >> weight;
            if (weight != -1 && i != j) {
                graph[i].push_back({j, weight});
            }
        }
    }
    
    vector<int> dist;
    dijkstra(s, n, graph, dist);
    
    if (dist[f] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[f] << endl;
    }
    
    return 0;
}
