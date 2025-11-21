#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct Point {
    ll x, y;
};

ld point_line_dist(Point p, Point p1, Point p2) {
    ld A = p1.y - p2.y;
    ld B = p2.x - p1.x;
    ld C = -A * p1.x - B * p1.y;

    ld num = abs(A * p.x + B * p.y + C);
    ld den = sqrt(A * A + B * B);

    return num / den;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> vertices(n);
    for (int i = 0; i < n; ++i) {
        cin >> vertices[i].x >> vertices[i].y;
    }

    ld min_h = 1e18;

    for (int i = 0; i < n; ++i) {
        Point p_prev = vertices[(i - 1 + n) % n];
        Point p_curr = vertices[i];
        Point p_next = vertices[(i + 1) % n];

        min_h = min(min_h, point_line_dist(p_curr, p_prev, p_next));
    }

    cout << fixed << setprecision(10) << min_h / 2.0 << endl;
}

int main() {
    solve();
    return 0;
}
