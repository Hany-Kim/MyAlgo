#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <typeinfo>

using namespace std;


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, E;
    cin >> n >> E;
    vector<vector<int>> edge, road;
    vector<int> v;
    v.clear();
    for (int i = 0; i < n + 1; i++) edge.push_back(v);
    for (int i = 0; i < n + 1; i++) v.push_back(0);
    for (int i = 0; i < n + 1; i++) road.push_back(v);

    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        road[a][b] = c;
        edge[a].push_back(b);
    }
    int ans = numeric_limits<int>::max();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    int visit[n + 1];
    int node, ntime, node2, ntime2;
    for (int s = 1; s <= n; s++) {
        while (!q.empty()) q.pop();
        q.push({ 0, s });
        for (int i = 0; i < n + 1; i++) visit[i] = 0;
        while (!q.empty()) {
            node = q.top()[1];
            ntime = q.top()[0];
            q.pop();
            if (visit[node] > ntime) {
                continue;
            }
            if (ntime > 0 && node == s) break;

            for (int j = 0; j < edge[node].size(); j++) {
                node2 = edge[node][j];
                ntime2 = ntime + road[node][node2];
                if (ans <= ntime2) continue;
                if (visit[node2] != 0 && visit[node2] < ntime2) continue;
                q.push({ ntime2, node2 });
                visit[node2] = ntime2;
            }
        }

        if (visit[s] == 0) continue;
        //ans = min(ans, visit[s]);
        if (ans > visit[s]) ans = visit[s];
    }
    if (ans == numeric_limits<int>::max()) cout << "-1\n";
    else cout << ans << '\n';

    return 0;
}