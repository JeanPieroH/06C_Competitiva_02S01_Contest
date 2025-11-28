#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct Point {
    ll r, c;
};

bool comparePoints(const Point& a, const Point& b) {
    if (a.r != b.r) {
        return a.r < b.r;
    }
    return a.c < b.c;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) cin >> points[i].r;
    for (int i = 0; i < n; i++) cin >> points[i].c;

    sort(points.begin(), points.end(), comparePoints);

    ll cost = 0;
    Point current = {1, 1};
    for (int i = 0; i < n; i++) {
        if (current.r == points[i].r && current.c == points[i].c) {
            continue;
        }
        ll dr = points[i].r - current.r;
        ll dc = points[i].c - current.c;

        if ((current.r + current.c) % 2 == 1 && dr == dc) {
            // No cost
        } else {
             if (dr == dc) {
                 cost += dr;
             } else {
                 if ((current.r + current.c) % 2 == 0) {
                     cost += (dr - dc) / 2;
                 } else {
                     cost += (dr - dc + 1) / 2;
                 }
             }
        }
        current = points[i];
    }
    cout << cost << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
