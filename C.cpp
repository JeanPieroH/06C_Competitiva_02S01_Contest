#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int MAXN = 1005;
int r, c;
char grid[MAXN][MAXN];
int dist_S[MAXN][MAXN];
int dist_E[MAXN][MAXN];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool is_valid(int x, int y) {
    return x >= 0 && x < r && y >= 0 && y < c && grid[x][y] != 'T';
}

void bfs(int start_x, int start_y, int dist[MAXN][MAXN]) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            dist[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    dist[start_x][start_y] = 0;
    q.push({start_x, start_y});

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            if (is_valid(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[curr.first][curr.second] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void solve() {
    cin >> r >> c;
    int start_x, start_y, exit_x, exit_y;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
            if (grid[i][j] == 'E') {
                exit_x = i;
                exit_y = j;
            }
        }
    }

    bfs(exit_x, exit_y, dist_E);
    int path_dist = dist_E[start_x][start_y];
    ll battles = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (isdigit(grid[i][j])) {
                if (dist_E[i][j] != -1 && dist_E[i][j] <= path_dist) {
                    battles += (grid[i][j] - '0');
                }
            }
        }
    }
    cout << battles << endl;
}

int main() {
    solve();
    return 0;
}
