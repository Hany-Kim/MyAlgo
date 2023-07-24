#include <stdio.h>
#include <vector>

using namespace std;

int TC;
int N, M, Q;
vector<vector<int>> A;
vector<int> rowToColPoint, colToRowPoint;
int ans;

void init() {
    A.clear();
    rowToColPoint.clear();
    colToRowPoint.clear();
    ans = 0;
}

void input() {
    scanf("%d %d %d", &N, &M, &Q);

    A = vector<vector<int>>((N + 1), vector<int>(M + 1));
    rowToColPoint = vector<int>(N + 1);
    colToRowPoint = vector<int>(M + 1);

    for (register int y = 1; y <= N; ++y) {
        for(register int x = 1; x <= M; ++x){
            scanf("%d", &A[y][x]);
            A[y][0] = max(A[y][0], A[y][x]);
            A[0][x] = max(A[0][x], A[y][x]);
        }
    }
}
void setting() {
    for (register int y = 1; y <= N; ++y) {
        for (register int x = 1; x <= M; ++x) {
            if (A[y][0] == A[y][x] && A[0][x] == A[y][x]) {
                rowToColPoint[y] = x;
                colToRowPoint[x] = y;
            }
        }
    }
}

void update_cell(int r, int c, int x) {
    A[r][c] = x;
    if (x > A[r][0]) {
        A[r][0] = x;
        rowToColPoint[r] = c;
    }
    if (x > A[0][c]) {
        A[0][c] = x;
        colToRowPoint[c] = r;
    }
}

void check_safe_cell() {
    if (N <= M) {
        for (register int row = 1; row <= N; ++row) {
            if (row == colToRowPoint[rowToColPoint[row]]) ++ans;
        }
    }
    else if (N > M) {
        for (register int col = 1; col <= M; ++col) {
            if (col == rowToColPoint[colToRowPoint[col]]) ++ans;
        }
    }
}

void sol() {
    setting(); // O(N*M)
    for (register int query = 0; query < Q; ++query) {
        int r = 0, c = 0, x = 0;
        scanf("%d %d %d", &r, &c, &x);

        update_cell(r, c, x);

        check_safe_cell(); // O ( N + M )
    }

    printf("%d", ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &TC);

    for (register int testcase = 1; testcase <= TC; ++testcase) {
        printf("#%d ", testcase);
        init();
        input();
        sol();
        printf("\n");
    }

    return 0;
}