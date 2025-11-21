#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int MAXN = 105;
const double INF = 1e9;

struct Point {
    double x, y;
};

Point inner_polygon[MAXN];
Point outer_polygon[MAXN];

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double point_segment_dist(Point p, Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;

    if (dx == 0 && dy == 0) {
        return dist(p, p1);
    }

    double t = ((p.x - p1.x) * dx + (p.y - p1.y) * dy) / (dx * dx + dy * dy);

    if (t < 0) {
        return dist(p, p1);
    }
    if (t > 1) {
        return dist(p, p2);
    }

    Point projection = { p1.x + t * dx, p1.y + t * dy };
    return dist(p, projection);
}

void solve() {
    int n_inner, n_outer;
    cin >> n_inner;
    for (int i = 0; i < n_inner; ++i) {
        cin >> inner_polygon[i].x >> inner_polygon[i].y;
    }
    cin >> n_outer;
    for (int i = 0; i < n_outer; ++i) {
        cin >> outer_polygon[i].x >> outer_polygon[i].y;
    }

    double min_dist = INF;

    for (int i = 0; i < n_inner; ++i) {
        for (int j = 0; j < n_outer; ++j) {
            min_dist = min(min_dist, point_segment_dist(inner_polygon[i], outer_polygon[j], outer_polygon[(j + 1) % n_outer]));
        }
    }

    for (int i = 0; i < n_outer; ++i) {
        for (int j = 0; j < n_inner; ++j) {
            min_dist = min(min_dist, point_segment_dist(outer_polygon[i], inner_polygon[j], inner_polygon[(j + 1) % n_inner]));
        }
    }

    cout << fixed << setprecision(8) << min_dist / 2.0 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
