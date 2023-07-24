#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[16][16];
int marketTobase[31][16][16]; // ���� -> ���̽�ķ�� [m��������][x][y]  // ��Ȱ�� �Ұ�, �����ִ� ��� �ٽ� ��� ã�ƾ���, �޸� �ʰ����� �ٲ���
int baseToMarket[31][16][16]; // ���̽�ķ�� -> ���� [m�����][x][y]
struct Node {
    int x;
    int y;
};
Node market[31]; // �ε��� 0~
vector<Node> inside_person; // �ε��� 0~
bool arrive_person[30];
int dist[30];
int cnt[30];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
vector<Node> basecamp_list;

int t;

void init() {
    for (int z = 0; z < 31; z++) { // �ִܰŸ� ����� �迭 �ʱ�ȭ
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
            if (marketTobase[market_num][nx][ny] != -1) continue; // �̹� ������ ĭ
            if (map[nx][ny] == 2) continue; // �̵� �Ұ� ĭ

            marketTobase[market_num][nx][ny] = marketTobase[market_num][now.x][now.y] + 1;

            if (map[nx][ny] == 1) { // ���̽�ķ���� ã�Ҵ�
                basecamp_list.push_back({ nx,ny });
            }

            q.push({ nx,ny });
        }
    }

    // ��� ��ķ�� ���� ������
    sort(basecamp_list.begin(), basecamp_list.end(), basecamp_sort);

    // ���ھȿ� ��� �ֱ�
    Node myBasecamp = basecamp_list[0];
    inside_person.push_back({ myBasecamp }); // t�� ����� ��ǥ�� �迭�� t��° �ε����� ����
    map[myBasecamp.x][myBasecamp.y] = 2; // ��ķ�� �����
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
            inside_person[idx].x = nx; // ��� ��ĭ �̵�
            inside_person[idx].y = ny;
            break;
        }
    }
}
void update_path(int market_num, Node start) {
    for (int x = 0; x < 16; x++) { // �ٽ� �ʱ�ȭ
        for (int y = 0; y < 16; y++) {
            marketTobase[market_num][x][y] = -1;
        }
    }
    queue<Node> q;

    marketTobase[market_num][start.x][start.y] = 0;
    q.push(start);

    int flag = 0; // ��� ã�� �÷���
    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx<1 || nx>n || ny<1 || ny>n) continue;
            if (marketTobase[market_num][nx][ny] != -1) continue; // �̹� ������ ĭ
            if (map[nx][ny] == 2 && (nx != inside_person[market_num].x && ny != inside_person[market_num].y)) continue; // �̵� �Ұ� ĭ && ����ڴ� �ڽ��� ��ķ���� �̵� �Ұ� ĭ�� �ִ� => ������Ʈ ������ �Ʒ� ������ ��������

            marketTobase[market_num][nx][ny] = marketTobase[market_num][now.x][now.y] + 1;

            //if (nx == inside_person[market_num].x && ny == inside_person[market_num].y) { // ����� ã�Ҵ�
            //    flag = 1;
            //    break;
            //}

            q.push({ nx,ny });
        }
        //if (flag) break;
    }
}
void up_date_find_basecamp(int market_num, Node start) {
    for (int x = 0; x < 16; x++) { // �ٽ� �ʱ�ȭ
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
            if (marketTobase[market_num][nx][ny] != -1) continue; // �̹� ������ ĭ
            if (map[nx][ny] == 2) continue; // �̵� �Ұ� ĭ

            marketTobase[market_num][nx][ny] = marketTobase[market_num][now.x][now.y] + 1;

            if (nx == inside_person[market_num].x && ny == inside_person[market_num].y) { // ���̽�ķ���� ã�Ҵ�
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
    for (int i = 0; i < m; i++) { // ������ ��ġ
        cin >> market[i].x >> market[i].y;
    }

    init();

    while (t < m) {
        if (!inside_person.empty()) { // 1. ���ڳ� ���� ����� ������
           
           for (int i = 0; i < inside_person.size(); i++) {
                if (arrive_person[i] == true) continue;
                move_person(i); // ����� ������� ��ĭ�� �̵�
                if (inside_person[i].x == market[i].x && inside_person[i].y == market[i].y) { // ������ ����
                   map[market[i].x][market[i].y] = 2;
                   arrive_person[i] = true;
                }
           }
           for (int j = 0; j < inside_person.size(); j++) { // ������ ��� ����, ��� �缳��
               if (arrive_person[j] == true) continue;
               update_path(j, market[j]);
           }
        }
        // 3. t�� ����� t�� �������� ���� ����� ��ķ���� ��
        // ��ķ ���� �켱���� �Ÿ� ª��, �� �۰�, �� �۰�
        basecamp_list.clear();
        find_basecamp(t, market[t]); // ��ķ�� �ִ´�.
        dist[t] = marketTobase[t][inside_person[t].x][inside_person[t].y];

        output();

        ++t;
    }

    while (1) {
        for (int i = 0; i < inside_person.size(); i++) {
            if (arrive_person[i] == true) continue;
            move_person(i); // ����� ������� ��ĭ�� �̵�
            if (inside_person[i].x == market[i].x && inside_person[i].y == market[i].y) { // ������ ����
                map[market[i].x][market[i].y] = 2;
                arrive_person[i] = true;
            }
        }
        for (int j = 0; j < inside_person.size(); j++) { // ������ ��� ����, ��� �缳��
            if (arrive_person[j] == true) continue;
            update_path(j, market[j]);
            dist[j] = marketTobase[j][inside_person[j].x][inside_person[j].y];
        }
        if (isAllarrive()) break;
        ++t;
    }

    /*
    for (int i = 0; i < inside_person.size(); i++) {
        if (arrive_person[i] == false) { // �������� �ֵ� �߿���
            if (dist[i] != 0) {
                update_path(i, market[i]);
                dist[i] -= 1;
            }
        }
    }

    int isArrive_flag = 0;
    for (int i = 0; i < m; i++) {
        if (arrive_person[i] == false) { // ���� �������� �������� ���� ����� �ִٸ�
            isArrive_flag = 1;
            break;
        }
    }

    // �����
    if (isArrive_flag) { // ���� �������� ���� ������� �ִ�.
        bool all_arrive_flag = true;
        int diff = 0;
        while (1) {// �ݺ��Ѵ�.
           //for (int i = 0; i < 30; i++) {
           //   dist[i] = diff * -1;
           //}
            all_arrive_flag = true;
            int now_process = 0;
            for (int i = 0; i < m; i++) {
                if (arrive_person[i] == false) { // ���� ���� ���ߴ��� ã�´�.
                    if (dist[i] == 0) {
                        update_path(i, market[i]);// �󸶳� ���Ҵ��� ����Ѵ�.
                        dist[i] += marketTobase[i][inside_person[i].x][inside_person[i].y];
                    }

                    if (dist[i] <= 1 && arrive_person[i] == false) {// �ٷ� �� �� �ִ��� Ȯ���Ѵ�.
                        now_process = 1;
                    }
                    all_arrive_flag = false;
                }
            }
            if (all_arrive_flag) break;

            if (now_process == 1) {
                for (int i = 0; i < m; i++) {
                    if (arrive_person[i] == false) { // ���� ���� ���ߴ��� ã�´�.
                        if (dist[i] <= 1 && arrive_person[i] == false) {// �ٷ� �� �� �ִ��� Ȯ���Ѵ�.
                            map[market[i].x][market[i].y] = 2;// �� �� ������ �ٷ� �־��ش�
                            arrive_person[i] = true;
                            dist[i] = 0;
                        }
                        else if (arrive_person[i] == false) dist[i] -= 1; // ���� -1�� ���ش�
                    }
                }
                ++t;
            }

            all_arrive_flag = true;
            for (int i = 0; i < m; i++) {
                if (arrive_person[i] == false) { // ���� ���� ���ߴ��� ã�´�.
                    all_arrive_flag = false;
                }
            }
            if (all_arrive_flag) break;
            int pmin = 213456789;
            int who = 0;
            for (int i = 0; i < m; i++) {
                if (arrive_person[i] == false) { // ������ �������鼭
                    if (pmin > dist[i]) { // ���� �� �ȳ��� ����� ã�´�.
                        pmin = dist[i];
                        who = i;
                    }
                }
            }
            arrive_person[who] = true; // �׻���� ������Ű��
            map[market[who].x][market[who].y] = 2;
            diff = pmin;

            //output();
            t += pmin; // �Ÿ���ŭ t�� ���Ѵ�.
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
          if (!inside_person.empty()) { // 1. ���ڳ� ���� ����� ������
             for (int i = 0; i < inside_person.size(); i++) {
                if (arrive_person[i] == true) continue;
                move_person(i); // ����� ������� ��ĭ�� �̵�
                if (inside_person[i].x == market[i].x && inside_person[i].y == market[i].y) { // ������ ����
                   map[market[i].x][market[i].y] = 2;
                   arrive_person[i] = true;
                   for (int j = 0; j < inside_person.size(); j++) { // ������ ��� ����, ��� �缳��
                      if (arrive_person[j] == true) continue;
                      update_path(j, market[j]);
                   }
                }
             }
          }

          bool all_arrive_flag = true;
          for (int i = 0; i < m; i++) {
             if (arrive_person[i] == false) { // ���� �������� �������� ���� ����� �ִٸ�
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

    cout << t;// ����
}
int main() {
    freopen_s(new FILE*, "input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    return 0;
}