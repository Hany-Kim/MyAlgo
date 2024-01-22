#include <string>
#include <vector>
#include <queue>

using namespace std;

#define N_MAX 52 * 2
#define FOR(i,s,e) for(int i=s; i<e; ++i)

/*
알고 가야할 점

문제 상으로는 좌하단부터 (0,0)이지만
제 코드는 좌상단을 (0,0)으로 가정하였습니다.

직사각형의 크기(or 좌표)를 2배를 늘렸습니다.
좌표그대로 입력을 받으니 그림상으로 떨어져있는 위치이지만 연결된 것으로 인식하는 문제가 있었습니다.
이에 입력받은 좌표를 2배 늘려 크기 또한 2배로 늘렸습니다.
ex) 0 : 빈공간 / 1 : 사각형 내부 / 2 : 테두리
0 0 0 0 0 0 0 0 0
0 2 2 2 2 2 2 2 0   사각형을 2배로 늘리지 않으면,
0 2 1 1 1 1 1 2 0   왼쪽과 같은 문제가 생깁니다..
0 2 1 1 1 1 1 2 0   
0 2 2 2 1 1 2 2 0   기대값 17
0 0 0 2 1 1 2 0 0   실제출력값 16
0 0 2 2 1 1 2 2 2
0 0 2 1 1 1 1 1 2   실제 그림을 그려보면
0 0 2 2 2 1 2 2 2   (행, 열) 기준 (5,4)와 (6,4) 지점도 테두리(2) 이어야 합니다.
0 0 0 0 2 2 2 0 0   하지만 좌표를 그대로 사용하다보니 아래 코드에 대해선 겹쳐진 부분이라 테두리로 인지하지 못합니다.

두배로 늘린다면?
아래와 같습니다.

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0     2배로 늘린 방법)
0 2 2 2 2 2 2 2 2 2 2 2 2 2 0 0     좌표 1 --2배--> (1 * 2) - 1 = 1
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0     좌표 3 --2배--> (3 * 2) - 1 = 5
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0     와 같습니다.
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0     구분 되어야할 테두리가 붙기 때문에 떨어뜨린 것과 같은 효과를 얻었습니다.
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 2 2 2 2 1 1 1 1 1 2 2 2 0 0
0 0 0 0 0 2 1 1 1 1 1 2 0 0 0 0
0 0 0 0 0 2 2 2 1 1 1 2 0 0 0 0
0 0 0 0 0 0 0 2 1 1 1 2 0 0 0 0
0 0 0 2 2 2 2 2 1 1 1 2 2 2 2 2
0 0 0 2 1 1 1 1 1 1 1 1 1 1 1 2
0 0 0 2 1 1 1 1 1 1 1 1 1 1 1 2
0 0 0 2 1 1 1 1 1 1 1 1 1 1 1 2
0 0 0 2 2 2 2 2 1 1 1 2 2 2 2 2
0 0 0 0 0 0 0 2 1 1 1 2 0 0 0 0
0 0 0 0 0 0 0 2 2 2 2 2 0 0 0 0

참고) 2배로 늘리지 않았다면 확대해보면 아래 그림처럼 인식되었습니다.

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 2 2 2 2 2 2 2 2 2 2 2 2 2 0 0
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 1 1 1 1 1 1 1 1 1 1 1 2 0 0
0 2 2 2 2 2 1 1 1 1 1 2 2 2 0 0
0 0 0 0 0 2 1 1 1 1 1 2 0 0 0 0
0 0 0 0 0 2 1 1 1 1 1 2 0 0 0 0
0 0 0 0 0 2 1 1 1 1 1 2 0 0 0 0
0 0 0 2 2 2 1 1 1 1 1 2 2 2 2 2
0 0 0 2 1 1 1 1 1 1 1 1 1 1 1 2
0 0 0 2 1 1 1 1 1 1 1 1 1 1 1 2
0 0 0 2 1 1 1 1 1 1 1 1 1 1 1 2
0 0 0 2 2 2 2 2 1 1 1 2 2 2 2 2
0 0 0 0 0 0 0 2 1 1 1 2 0 0 0 0
0 0 0 0 0 0 0 2 2 2 2 2 0 0 0 0
*/

int sq_map[N_MAX][N_MAX]; // 직사각형을 그려서 형태를 저장
int map[N_MAX][N_MAX]; //
int route[N_MAX][N_MAX];

int dy[8] = { 0,1,0,-1,1,1,-1,-1 }; // 동 남 서 북 (대각선 * 4)
int dx[8] = { 1,0,-1,0,1,-1,1,-1 };

void create_rectangle(vector<int> rectangle_point) {
    /*
    sq_map에 직사각형을 생성해주는 함수
    */
    int top_y = (rectangle_point[1] * 2) - 1; // 입력받은 좌하단y좌표를 상단y로 뒤집어서 저장
    int bottom_y = (rectangle_point[3] * 2) - 1; // 입력받은 우상단y좌표를 하단y로 뒤집어서 저장

    int front_x = (rectangle_point[0] * 2) - 1;
    int end_x = (rectangle_point[2] * 2) - 1;

    //-----------------------------------------------------
    // 직사각형의 영역을 1로 표현함
    FOR(y, top_y, bottom_y + 1) {
        FOR(x, front_x, end_x + 1) {
            sq_map[y][x] = 1;
        }
    }
    //-----------------------------------------------------
}

bool isBorder(pair<int,int> now) {
    // 상하좌우 대각선을 탐색해 0과 인접한지 확인
    FOR(i, 0, 8) {
        int ny = now.first + dy[i];
        int nx = now.second + dx[i];

        if (ny < 0 || ny>N_MAX || nx < 0 || nx>N_MAX) continue;

        if (sq_map[ny][nx] == 0) return true;
    }
    return false;
}

void draw_border(vector<int> rectangle_point) {
    /*
    bfs 탐색기법을 통해 테두리를 찾음
    sq_map상에서 1인 좌표가 
    상하좌우 그리고 대각선으로 0과 인접하다면 테두리 임.
    */
    queue<pair<int, int>> q;
    int used[N_MAX][N_MAX] = { 0, };

    int sy = (rectangle_point[1] * 2) - 1;
    int sx = (rectangle_point[0] * 2) - 1;

    q.push(make_pair(sy, sx));
    used[sy][sx] = 1;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        //-----------------------------------------
        // 현재 좌표가 테두리인지 확인
        // 테두리라면 2로 used배열에 기록해둠
        if (isBorder(now) == true) {
            used[now.first][now.second] = 2;
        }
        //-----------------------------------------

        FOR(i, 0, 4) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];

            if (ny < 1 || ny>N_MAX || nx < 1 || nx>N_MAX) continue; // 맵의 크기를 벗어남
            if (sq_map[ny][nx] != 1) continue; // 직사각형이 아니라면
            if (used[ny][nx] != 0) continue; // 이미 방문했다면

            used[ny][nx] = 1;
            q.push(make_pair(ny, nx));
        }
    }

    //-------------------------------------------------
    // used배열에서 테두리 영역만 route배열에 복사
    FOR(y, 0, N_MAX) {
        FOR(x, 0, N_MAX) {
            if (used[y][x] == 2) route[y][x] = 1;
        }
    }
    //-------------------------------------------------
}


int find_route(int characterX, int characterY, int itemX, int itemY) {
    // bfs 탐색을 이용해
    // 테두리 영역을 따라가 도착 지점까지 최소거리를 찾음
    queue<pair<int, int>> q;
    int used[N_MAX][N_MAX] = { 0, };


    // 2배로 늘린 좌표 적용
    int sy = (characterY * 2) - 1;
    int sx = (characterX * 2) - 1;
    int gy = (itemY * 2) - 1;
    int gx = (itemX * 2) - 1;

    q.push(make_pair(sy, sx));
    used[sy][sx] = 1;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        FOR(i, 0, 4) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];

            if (ny < 1 || ny>N_MAX || nx < 1 || nx>N_MAX) continue; // 맵의 크기를 벗어남
            if (route[ny][nx] != 1) continue; // 테두리 영역이 아니라면
            if (used[ny][nx] != 0) continue; // 이미 방문했다면

            used[ny][nx] = used[now.first][now.second] + 1;
            if ((ny == gy) && (nx == gx)) // 아이템을 주우면 빠져나감
                return used[ny][nx];
            q.push(make_pair(ny, nx));
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    // 직사각형 별로 좌표를 순서대로 입력받아 sq_map에 그려줍니다.
    FOR(num, 0, rectangle.size()) {
        create_rectangle(rectangle[num]);
    }

    // 겹쳐진 직사각형에서 테두리라인만 추출해줍니다.
    draw_border(rectangle[0]);

    // 캐릭터가 아이템까지 도착하는 최소 경로를 지정해줍니다.
    // (나누기 2)를 한 이유는 직사각형의 크기를 2배로 늘렸기 때문입니다.
    answer = (find_route(characterX, characterY, itemX, itemY) / 2);

    return answer;
}
