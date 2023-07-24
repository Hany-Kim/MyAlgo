#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[16][16];
int marketTobase[31][16][16]; // 마켓 -> 베이스캠프 [m번편의점][x][y]  // 재활용 불가, 막혀있는 경우 다시 경로 찾아야함, 메모리 초과나면 바꾸자
int baseToMarket[31][16][16]; // 베이스캠프 -> 마켓 [m번사람][x][y]
struct Node {
    int x;
    int y;
};
Node market[31]; // 인덱스 0~
vector<Node> inside_person; // 인덱스 0~
bool arrive_person[30];
int dist[30];
int cnt[30];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
vector<Node> basecamp_list;

int t;

void init() {
    for (int z = 0; z < 31; z++) { // 최단거리 기록할 배열 초기화
        for (int x = 0; x < 16; x++) {
            for (int y = 0; y < 16; y++) {
                marketTobase[z][x][y] = -1;
            }
        }
    }
}
bool basecamp_sort(Node left, Node right) {
    if (marketTobase[t][left.x][left.y] <= marketTobase[t][right.x][right.y]) {
        if (marketTobase[t][left.x][left.y] == marketTobase[t][right.x][right.y]) {
            if (left.x <= right.x) {
                if (left.x == right.x) {
                    if (left.y < right.y) {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
void find_basecamp(int market_num, Node start) {
    queue<Node> q;

    marketTobase[market_num][start.x][start.y] = 0;
    q.push(start);

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx<1 || nx>n || ny<1 || ny>n) continue;
            if (marketTobase[market_num][nx][ny] != -1) continue; // 이미 지나온 칸
            if (map[nx][ny] == 2) continue; // 이동 불가 칸

            marketTobase[market_num][nx][ny] = marketTobase[market_num][now.x][now.y] + 1;

            if (map[nx][ny] == 1) { // 베이스캠프를 찾았다
                basecamp_list.push_back({ nx,ny });
            }

            q.push({ nx,ny });
        }
    }

    // 어느 베캠이 제일 가깝냐
    sort(basecamp_list.begin(), basecamp_list.end(), basecamp_sort);

    // 격자안에 사람 넣기
    Node myBasecamp = basecamp_list[0];
    inside_person.push_back({ myBasecamp }); // t번 사람의 좌표를 배열의 t번째 인덱스에 넣음
    map[myBasecamp.x][myBasecamp.y] = 2; // 베캠에 사람들어감
}
void output() {
    cout << "t: " << t + 1 << '\n';
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            cout << map[x][y] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
void move_person(int idx) {
    Node pnow = inside_person[idx];


    for (int i = 0; i < 4; i++) {
        int nx = pnow.x + dx[i];
        int ny = pnow.y + dy[i];

        if (nx<1 || nx>n || ny<1 || ny>n)continue;
        if (map[nx][ny] == 2) continue;

        if (marketTobase[idx][nx][ny] == marketTobase[idx][pnow.x][pnow.y] - 1) {
            inside_person[idx].x = nx; // 사람 한칸 이동
            inside_person[idx].y = ny;
            break;
        }
    }
}
void update_path(int market_num, Node start) {
    for (int x = 0; x < 16; x++) { // 다시 초기화
        for (int y = 0; y < 16; y++) {
            marketTobase[market_num][x][y] = -1;
        }
    }
    queue<Node> q;

    marketTobase[market_num][start.x][start.y] = 0;
    q.push(start);

    int flag = 0; // 사람 찾은 플래그
    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx<1 || nx>n || ny<1 || ny>n) continue;
            if (marketTobase[market_num][nx][ny] != -1) continue; // 이미 지나온 칸
            if (map[nx][ny] == 2 && (nx != inside_person[market_num].x && ny != inside_person[market_num].y)) continue; // 이동 불가 칸 && 사용자는 자신의 베캠에서 이동 불가 칸에 있다 => 업데이트 했을때 아래 조건을 만족못함

            marketTobase[market_num][nx][ny] = marketTobase[market_num][now.x][now.y] + 1;

            //if (nx == inside_person[market_num].x && ny == inside_person[market_num].y) { // 사람을 찾았다
            //    flag = 1;
            //    break;
            //}

            q.push({ nx,ny });
        }
        //if (flag) break;
    }
}
void up_date_find_basecamp(int market_num, Node start) {
    for (int x = 0; x < 16; x++) { // 다시 초기화
        for (int y = 0; y < 16; y++) {
            marketTobase[market_num][x][y] = -1;
        }
    }
    queue<Node> q;

    marketTobase[market_num][start.x][start.y] = 0;
    q.push(start);

    int flag = 0;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx<1 || nx>n || ny<1 || ny>n) continue;
            if (marketTobase[market_num][nx][ny] != -1) continue; // 이미 지나온 칸
            if (map[nx][ny] == 2) continue; // 이동 불가 칸

            marketTobase[market_num][nx][ny] = marketTobase[market_num][now.x][now.y] + 1;

            if (nx == inside_person[market_num].x && ny == inside_person[market_num].y) { // 베이스캠프를 찾았다
                flag = 1;
                break;
            }

            q.push({ nx,ny });
        }
        if (flag) break;
    }
}
bool isAllarrive() {
    bool fflag = true;
    
    for (int i = 0; i < m; i++) {
        if (arrive_person[i] == false) {
            fflag = false;
            break;
        }
    }
    return fflag;
}
void sol() {
    cin >> n >> m;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            cin >> map[x][y];
        }
    }
    for (int i = 0; i < m; i++) { // 편의점 위치
        cin >> market[i].x >> market[i].y;
    }

    init();

    while (t < m) {
        if (!inside_person.empty()) { // 1. 격자내 들어온 사람이 있을때
           
           for (int i = 0; i < inside_person.size(); i++) {
                if (arrive_person[i] == true) continue;
                move_person(i); // 사람을 순서대로 한칸씩 이동
                if (inside_person[i].x == market[i].x && inside_person[i].y == market[i].y) { // 편의점 도착
                   map[market[i].x][market[i].y] = 2;
                   arrive_person[i] = true;
                }
           }
           for (int j = 0; j < inside_person.size(); j++) { // 도착한 사람 빼고, 경로 재설정
               if (arrive_person[j] == true) continue;
               update_path(j, market[j]);
           }
        }
        // 3. t번 사람은 t번 편의점과 가장 가까운 베캠으로 들어감
        // 베캠 선정 우선순위 거리 짧고, 행 작고, 열 작고
        basecamp_list.clear();
        find_basecamp(t, market[t]); // 베캠에 넣는다.
        dist[t] = marketTobase[t][inside_person[t].x][inside_person[t].y];

        output();

        ++t;
    }

    while (1) {
        for (int i = 0; i < inside_person.size(); i++) {
            if (arrive_person[i] == true) continue;
            move_person(i); // 사람을 순서대로 한칸씩 이동
            if (inside_person[i].x == market[i].x && inside_person[i].y == market[i].y) { // 편의점 도착
                map[market[i].x][market[i].y] = 2;
                arrive_person[i] = true;
            }
        }
        for (int j = 0; j < inside_person.size(); j++) { // 도착한 사람 빼고, 경로 재설정
            if (arrive_person[j] == true) continue;
            update_path(j, market[j]);
            dist[j] = marketTobase[j][inside_person[j].x][inside_person[j].y];
        }
        if (isAllarrive()) break;
        ++t;
    }

    /*
    for (int i = 0; i < inside_person.size(); i++) {
        if (arrive_person[i] == false) { // 도착못한 애들 중에서
            if (dist[i] != 0) {
                update_path(i, market[i]);
                dist[i] -= 1;
            }
        }
    }

    int isArrive_flag = 0;
    for (int i = 0; i < m; i++) {
        if (arrive_person[i] == false) { // 아직 편의점에 도착하지 못한 사람이 있다면
            isArrive_flag = 1;
            break;
        }
    }

    // 디버깅
    if (isArrive_flag) { // 아직 도착하지 못한 사람들이 있다.
        bool all_arrive_flag = true;
        int diff = 0;
        while (1) {// 반복한다.
           //for (int i = 0; i < 30; i++) {
           //   dist[i] = diff * -1;
           //}
            all_arrive_flag = true;
            int now_process = 0;
            for (int i = 0; i < m; i++) {
                if (arrive_person[i] == false) { // 누가 도착 못했는지 찾는다.
                    if (dist[i] == 0) {
                        update_path(i, market[i]);// 얼마나 남았는지 계산한다.
                        dist[i] += marketTobase[i][inside_person[i].x][inside_person[i].y];
                    }

                    if (dist[i] <= 1 && arrive_person[i] == false) {// 바로 갈 수 있는지 확인한다.
                        now_process = 1;
                    }
                    all_arrive_flag = false;
                }
            }
            if (all_arrive_flag) break;

            if (now_process == 1) {
                for (int i = 0; i < m; i++) {
                    if (arrive_person[i] == false) { // 누가 도착 못했는지 찾는다.
                        if (dist[i] <= 1 && arrive_person[i] == false) {// 바로 갈 수 있는지 확인한다.
                            map[market[i].x][market[i].y] = 2;// 갈 수 있으면 바로 넣어준다
                            arrive_person[i] = true;
                            dist[i] = 0;
                        }
                        else if (arrive_person[i] == false) dist[i] -= 1; // 매턴 -1씩 해준다
                    }
                }
                ++t;
            }

            all_arrive_flag = true;
            for (int i = 0; i < m; i++) {
                if (arrive_person[i] == false) { // 누가 도착 못했는지 찾는다.
                    all_arrive_flag = false;
                }
            }
            if (all_arrive_flag) break;
            int pmin = 213456789;
            int who = 0;
            for (int i = 0; i < m; i++) {
                if (arrive_person[i] == false) { // 도착을 못했으면서
                    if (pmin > dist[i]) { // 가장 얼마 안남은 사람을 찾는다.
                        pmin = dist[i];
                        who = i;
                    }
                }
            }
            arrive_person[who] = true; // 그사람을 도착시키고
            map[market[who].x][market[who].y] = 2;
            diff = pmin;

            //output();
            t += pmin; // 거리만큼 t에 더한다.
            for (int i = 0; i < m; i++) {
                if (arrive_person[i] == false) {
                    if (dist[i] == 0) dist[i] = (diff * -1) + 1;
                    else dist[i] = dist[i] + (diff * -1)  + 1;
                }
            }
        }
    }
    */

    /*
    if (isArrive_flag) {
       while (1) {
          if (!inside_person.empty()) { // 1. 격자내 들어온 사람이 있을때
             for (int i = 0; i < inside_person.size(); i++) {
                if (arrive_person[i] == true) continue;
                move_person(i); // 사람을 순서대로 한칸씩 이동
                if (inside_person[i].x == market[i].x && inside_person[i].y == market[i].y) { // 편의점 도착
                   map[market[i].x][market[i].y] = 2;
                   arrive_person[i] = true;
                   for (int j = 0; j < inside_person.size(); j++) { // 도착한 사람 빼고, 경로 재설정
                      if (arrive_person[j] == true) continue;
                      update_path(j, market[j]);
                   }
                }
             }
          }

          bool all_arrive_flag = true;
          for (int i = 0; i < m; i++) {
             if (arrive_person[i] == false) { // 아직 편의점에 도착하지 못한 사람이 있다면
                all_arrive_flag = false;
                break;
             }
          }
          if (all_arrive_flag) break;
          output();
          ++t;
       }
    }
    */

    cout << t;// 정답
}
int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    return 0;
}