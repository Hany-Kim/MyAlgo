#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int from;
    int to;
    int cost;
};

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, M;
        cin >> N >> M;

        vector<Edge> edges(M);
        vector<int> dist(N + 1, INF);

        for (int i = 0; i < M; i++) {
            int X, Y, C;
            cin >> X >> Y >> C;

            edges[i] = { X, Y, C };
        }

        bool hasCycle = false;
        int minCost = INF;

        for (int node = 1; node <= N; ++node) {
            dist[node] = 0;
            // Bellman-Ford algorithm
            for (int i = 1; i <= N - 1; i++) {
                for (int j = 0; j < M; j++) {
                    int from = edges[j].from;
                    int to = edges[j].to;
                    int cost = edges[j].cost;

                    if (dist[from] == INF) continue;
                    if (dist[to] > dist[from] + cost) {
                        dist[to] = dist[from] + cost;
                    }
                }
            }

            for (register int i = 0; i < M; ++i) {
                int from = edges[i].from;
                int to = edges[i].to;
                int cost = edges[i].cost;

                if (dist[from] == INF) continue;

            }
        }

        cout << "#" << tc << " ";

        if (hasCycle) {
            cout << minCost << endl;
        }
        else {
            cout << -1 << endl;
        }
    }

    return 0;
}
