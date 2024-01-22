#include <string>
#include <vector>
#include <queue>

using namespace std;

#define N_MAX 52 * 2
#define FOR(i,s,e) for(int i=s; i<e; ++i)

int sq_map[N_MAX][N_MAX];
int map[N_MAX][N_MAX];
int route[N_MAX][N_MAX];

int dy[8] = { 0,1,0,-1,1,1,-1,-1 };
int dx[8] = { 1,0,-1,0,1,-1,1,-1 };

bool isBorder(pair<int,int> now) {
    FOR(i, 0, 8) {
        int ny = now.first + dy[i];
        int nx = now.second + dx[i];

        if (ny < 0 || ny>N_MAX || nx < 0 || nx>N_MAX) continue;

        if (sq_map[ny][nx] == 0) return true;
    }
    return false;
}

void draw_border(vector<int> rectangle_point) {
    queue<pair<int, int>> q;
    int used[N_MAX][N_MAX] = { 0, };

    int sx = (rectangle_point[0] * 2) - 1;
    int sy = (rectangle_point[1] * 2) - 1;

    q.push(make_pair(sy, sx));
    used[sy][sx] = 1;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        if (isBorder(now) == true) {
            used[now.first][now.second] = 2;
        }

        FOR(i, 0, 4) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];

            if (ny < 1 || ny>100 || nx < 1 || nx>100) continue;
            if (sq_map[ny][nx] != 1) continue;
            if (used[ny][nx] != 0) continue;

            used[ny][nx] = 1;
            q.push(make_pair(ny, nx));
        }
    }

    FOR(y, 0, N_MAX) {
        FOR(x, 0, N_MAX) {
            if (used[y][x] == 2) route[y][x] = 1;
        }
    }
}

void create_rectangle(vector<int> rectangle_point) {
    int tmp[N_MAX][N_MAX] = { 0, };
    
    FOR(y, (rectangle_point[1] * 2) - 1, (rectangle_point[3] * 2)) {
        FOR(x, (rectangle_point[0] * 2) - 1, (rectangle_point[2] * 2)) {
            sq_map[y][x] = 1;
        }
    }
}

int find_route(int sx, int sy, int gx, int gy) {
    queue<pair<int, int>> q;
    int used[N_MAX][N_MAX] = { 0, };

    sx = (sx * 2) - 1;
    sy = (sy * 2) - 1;
    gx = (gx * 2) - 1;
    gy = (gy * 2) - 1;

    q.push(make_pair(sy, sx));
    used[sy][sx] = 1;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        FOR(i, 0, 4) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];

            if (ny < 1 || ny>100 || nx < 1 || nx>100) continue;
            if (route[ny][nx] != 1) continue;
            if (used[ny][nx] != 0) continue;

            used[ny][nx] = used[now.first][now.second] + 1;
            if ((ny == gy) && (nx == gx))
                return used[ny][nx];
            q.push(make_pair(ny, nx));
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    FOR(num, 0, rectangle.size()) {
        create_rectangle(rectangle[num]);
    }
    draw_border(rectangle[0]);
    answer = (find_route(characterX, characterY, itemX, itemY) / 2);

    return answer;
}