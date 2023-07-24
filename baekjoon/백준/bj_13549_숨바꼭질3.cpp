// 務晦 : X -> X-1 or X+1
// 牖除檜翕 : X -> 2X
#include <iostream>
#include <queue>
using namespace std;

int N, K;
int sec;
int map[100001];
long long dummy = 2134567890;
struct Edge
{
    int to;
    long long dist;
};

int nextDir[3] = { -1, 1, 2 };
vector<long long> dist(100001, dummy);

bool operator<(Edge left, Edge right) {
    if (left.dist < right.dist) return false;
    if (left.dist > right.dist) return true;

    return false;
}

void sol() {
    cin >> N >> K;
    // 5(0) -> 牖 10(0) -> 務 9(1) -> 牖 18(1) -> 務 17(2)

    int X = N;

    priority_queue<Edge> pq;

    dist[N] = 0;
    pq.push({ N, 0 });

    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();

        for (int i = 0; i < 3; i++) {
            
            if (i == 2) {
                int nidx = now.to * nextDir[i];
                if (nidx < 1 || nidx > 100000)continue;
                
                if (dist[nidx] < now.dist) continue;
                dist[nidx] = now.dist;

                pq.push({ nidx,dist[nidx] });
            }
            else {
                int nidx = now.to + nextDir[i];
                if (nidx < 0 || nidx > 100000)continue;
                
                if (dist[nidx] < now.dist + 1) continue;
                dist[nidx] = now.dist + 1;

                pq.push({ nidx,dist[nidx] });
            }
        }
    int de = 1;
    }
    cout << dist[K];
}

int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sol();

    return 0;
}