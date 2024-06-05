#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
};

int main() {
    int n;
    cin >> n;
    
    vector<int> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    
    int m;
    cin >> m;
    
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;  // индексация с 0
        graph[u].push_back({v});
        graph[v].push_back({u});
    }
    
    vector<int> dist(n, INF);
    dist[0] = cost[0];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({cost[0], 0});
    
    while (!pq.empty()) {
        int curr_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (curr_cost != dist[u]) continue;
        
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            if (dist[u] + cost[v] < dist[v]) {
                dist[v] = dist[u] + cost[v];
                pq.push({dist[v], v});
            }
        }
    }
    
    if (dist[n - 1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[n - 1] << endl;
    }
    
    return 0;
}
