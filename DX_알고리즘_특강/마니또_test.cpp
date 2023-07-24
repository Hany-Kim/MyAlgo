#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();  // 무한대 값으로 초기화

struct Edge {
    int to;
    int cost;
};

vector<int> dijkstra(const vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INF);  // 시작점으로부터의 최단 거리
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (dist[curNode] < curDist)
            continue;

        for (const Edge& edge : graph[curNode]) {
            int nextNode = edge.to;
            int nextDist = curDist + edge.cost;

            if (nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.push(make_pair(nextDist, nextNode));
            }
        }
    }

    return dist;
}

int main() {
    freopen("input2.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--;
        v--;

        graph[u].push_back({ v, cost });
    }

    int minCycle = INF;

    // 각 정점에서 다익스트라 알고리즘을 실행하여 최소 싸이클 찾기
    for (int start = 0; start < n; start++) {
        vector<int> dist = dijkstra(graph, start);

        for (const Edge& edge : graph[start]) {
            int end = edge.to;
            int cost = edge.cost;

            minCycle = min(minCycle, dist[end] + cost);
        }
    }

    if (minCycle == INF) {
        cout << "No cycle found." << endl;
    }
    else {
        cout << "Minimum cycle distance: " << minCycle << endl;
    }

    return 0;
}
