#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define FOR(i,s,e)  for(register int i=s;i<(e);++i)

int N, M, k;
int map[20][20];
int smell_map[20][20];
struct Info {
    bool isLive = false;
    int ly = 0, lx = 0;
    int seeDir = 0; // �ٶ󺸴� ����
    int priDir[5][5] = { 0, }; // ���⺰ �켱����
};
Info shark[401];
int dy[5] = { 0,-1,1,0,0 }; // 1:�� 2:�� 3:�� 4:��
int dx[5] = { 0,0,0,-1,1 };
int stime;

void input() {
    cin >> N >> M >> k;
    FOR(y, 0, N) {
        FOR(x, 0, N) {
            cin >> map[y][x];
            if (map[y][x] != 0) {
                shark[map[y][x]].isLive = true;
                shark[map[y][x]].ly = y;
                shark[map[y][x]].lx = x;
            }
        }
    }
    FOR(i, 1, M + 1) {
        int shark_num = i;
        cin >> shark[shark_num].seeDir;
    }
    FOR(num, 1, M + 1) {
        FOR(y, 1, 5) {
            FOR(x, 1, 5) {
                int shark_num = num;
                int dir = 0;
                cin >> dir;
                shark[shark_num].priDir[y][x] = dir;
            }
        }
    }
}
void spread_smell() {
    FOR(shark_num, 1, M + 1) {
        int num = shark_num;
        if (shark[num].isLive) { //��� ��� ������
            // ���� ��ġ�� ���� �ѷ�
            map[shark[num].ly][shark[num].lx] = num;
            smell_map[shark[num].ly][shark[num].lx] = k;
        }
    }
}
void cpy_map(int(*cpy_map)[20]) {
    FOR(y, 0, N) {
        FOR(x, 0, N) {
            cpy_map[y][x] = smell_map[y][x];
        }
    }
}
int check_next_pos(Info* now) {
    FOR(dir, 1, 5) {
        int ny = now->ly + dy[now->priDir[now->seeDir][dir]];
        int nx = now->lx + dx[now->priDir[now->seeDir][dir]];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

        if (smell_map[ny][nx] == 0) {
            return now->priDir[now->seeDir][dir];
        }
    }
    return 0; // �� �� ����.
}
void move_shark() {
    /*int pre_smell_map[20][20] = { 0, };
    cpy_map(pre_smell_map);*/

    FOR(shark_num, 1, M + 1) {
        if (shark[shark_num].isLive) { // ����ִ� �� ��ǥ ����
            int dir = check_next_pos(&shark[shark_num]);

            if (dir != 0) {
                //map[shark[shark_num].ly][shark[shark_num].lx] = 0;
                shark[shark_num].ly = shark[shark_num].ly + dy[dir];
                shark[shark_num].lx = shark[shark_num].lx + dx[dir];
                shark[shark_num].seeDir = dir;
            }
            else if (dir == 0) {
                FOR(i, 1, 5) {
                    int nDir = shark[shark_num].priDir[shark[shark_num].seeDir][i];
                    int ny = shark[shark_num].ly + dy[nDir];
                    int nx = shark[shark_num].lx + dx[nDir];

                    if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

                    if (map[ny][nx] == shark_num) {
                        //map[shark[shark_num].ly][shark[shark_num].lx] = 0;
                        shark[shark_num].ly = ny;
                        shark[shark_num].lx = nx;
                        shark[shark_num].seeDir = nDir;

                        break;
                    }
                }
            }
        }
    }

    FOR(shark_num, 1, M + 1) {
        if (shark[shark_num].isLive) { // ����ִ� �� �̵�
            if (map[shark[shark_num].ly][shark[shark_num].lx] != 0 && map[shark[shark_num].ly][shark[shark_num].lx] != shark_num) {
                shark[shark_num].isLive = false; // ��ĭ�� �ߺ� ��� ���̱�
            }
            else map[shark[shark_num].ly][shark[shark_num].lx] = shark_num;
        }
    }

    int de = 1;
}
void smell_minus() {
    FOR(y, 0, N) {
        FOR(x, 0, N) {
            if (smell_map[y][x] != 0) {
                smell_map[y][x] -= 1;
                if (smell_map[y][x] == 0) {
                    map[y][x] = 0;
                }
            }
        }
    }
}
bool check_one_shark() {
    FOR(num, 2, M + 1) {
        if (shark[num].isLive == true) return false;
    }
    return true;
}
void output() {
    FOR(y, 0, N) {
        FOR(x, 0, N) {
            cout << "(" << map[y][x] << ", " << smell_map[y][x] << ") ";
        }
        cout << '\n';
    }
}
void sol() {
    input();
    /*
    1�ʸ��� ���� 4ĭ�� �ϳ��� �̵� �� ���� �Ѹ�
       �̵�����
       1. ���� x => �ٶ󺸴� ���⿡ ���� �켱����
          �� ó�� �ٶ󺸴� ���� ����
          �̵����� => �ٶ󺸴� ������ �ȴ�
       2. ��ĭ�� �������� ������ ��ȣ�� ���� �� �������Ѵ�
    k�� �̵��ϸ� �����
    */
    while (1) {
        ++stime;
        //cout << stime << '\n';
        spread_smell(); // ��� M������ ������ �Ѹ�
        //output();
        //cout << "---------------------\n";
        move_shark();
        if (check_one_shark()) {
            cout << stime;
            break;
        }
        if (stime >= 1000) {
            cout << -1;
            break;
        }
        smell_minus();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    return 0;
}