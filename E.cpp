#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int r, c;
    cin >> r >> c;
    long long x, y;
    cin >> x >> y;
    vector<string> maze(n);
    for (int i = 0; i < n; ++i) {
        cin >> maze[i];
    }

    r--;
    c--;

    vector<vector<pair<long long, long long>>> dist(n, vector<pair<long long, long long>>(m, {1e18, 1e18}));
    deque<pair<int, int>> q;

    dist[r][c] = {0, 0};
    q.push_front({r, c});

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop_front();
        int curr_r = curr.first;
        int curr_c = curr.second;

        long long left_moves = dist[curr_r][curr_c].first;
        long long right_moves = dist[curr_r][curr_c].second;

        // Move Up
        if (curr_r > 0 && maze[curr_r - 1][curr_c] == '.') {
            if (left_moves <= dist[curr_r-1][curr_c].first && right_moves <= dist[curr_r-1][curr_c].second) {
                if (left_moves < dist[curr_r-1][curr_c].first || right_moves < dist[curr_r-1][curr_c].second) {
                    dist[curr_r - 1][curr_c] = {left_moves, right_moves};
                    q.push_front({curr_r - 1, curr_c});
                }
            }
        }
        // Move Down
        if (curr_r < n - 1 && maze[curr_r + 1][curr_c] == '.') {
             if (left_moves <= dist[curr_r+1][curr_c].first && right_moves <= dist[curr_r+1][curr_c].second) {
                if (left_moves < dist[curr_r+1][curr_c].first || right_moves < dist[curr_r+1][curr_c].second) {
                    dist[curr_r + 1][curr_c] = {left_moves, right_moves};
                    q.push_front({curr_r + 1, curr_c});
                }
            }
        }
        // Move Left
        if (curr_c > 0 && maze[curr_r][curr_c - 1] == '.' && left_moves < x) {
             if (left_moves + 1 <= dist[curr_r][curr_c - 1].first && right_moves <= dist[curr_r][curr_c - 1].second) {
                if (left_moves + 1 < dist[curr_r][curr_c - 1].first || right_moves < dist[curr_r][curr_c - 1].second) {
                   dist[curr_r][curr_c - 1] = {left_moves + 1, right_moves};
                   q.push_back({curr_r, curr_c - 1});
                }
            }
        }
        // Move Right
        if (curr_c < m - 1 && maze[curr_r][curr_c + 1] == '.' && right_moves < y) {
            if (left_moves <= dist[curr_r][curr_c + 1].first && right_moves + 1 <= dist[curr_r][curr_c + 1].second) {
                if (left_moves < dist[curr_r][curr_c + 1].first || right_moves + 1 < dist[curr_r][curr_c + 1].second) {
                    dist[curr_r][curr_c + 1] = {left_moves, right_moves + 1};
                    q.push_back({curr_r, curr_c + 1});
                }
            }
        }
    }

    long long reachable_cells = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dist[i][j].first != 1e18) {
                reachable_cells++;
            }
        }
    }
    cout << reachable_cells << endl;
}

int main() {
    solve();
    return 0;
}
