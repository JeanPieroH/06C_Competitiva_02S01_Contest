#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld PI = acos(-1.0);

struct Point {
    ld x, y;

    bool operator<(const Point& other) const {
        if (abs(x - other.x) > 1e-9) return x < other.x;
        return y < other.y;
    }
};

ld cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<Point> convex_hull(vector<Point>& points) {
    int n = points.size();
    if (n <= 2) return points;
    sort(points.begin(), points.end());

    vector<Point> lower_hull, upper_hull;

    for (const auto& p : points) {
        while (lower_hull.size() >= 2 && cross_product(lower_hull[lower_hull.size()-2], lower_hull.back(), p) <= 0) {
            lower_hull.pop_back();
        }
        lower_hull.push_back(p);
    }

    for (int i = n - 1; i >= 0; --i) {
        const auto& p = points[i];
        while (upper_hull.size() >= 2 && cross_product(upper_hull[upper_hull.size()-2], upper_hull.back(), p) <= 0) {
            upper_hull.pop_back();
        }
        upper_hull.push_back(p);
    }

    vector<Point> hull = lower_hull;
    for (size_t i = 1; i < upper_hull.size() - 1; ++i) {
        hull.push_back(upper_hull[i]);
    }
    return hull;
}

ld polygon_area(const vector<Point>& polygon) {
    ld area = 0.0;
    int n = polygon.size();
    if (n < 3) return 0.0;
    for (int i = 0; i < n; ++i) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return abs(area) / 2.0;
}


void solve() {
    int n_boards;
    cin >> n_boards;

    ld total_board_area = 0.0;
    vector<Point> all_corners;

    for (int i = 0; i < n_boards; ++i) {
        ld x, y, w, h, v;
        cin >> x >> y >> w >> h >> v;

        total_board_area += w * h;
        ld v_rad = v * PI / 180.0;
        ld cos_v = cos(v_rad);
        ld sin_v = sin(v_rad);

        ld w_vx = w / 2.0 * cos_v;
        ld w_vy = -w / 2.0 * sin_v;
        ld h_vx = h / 2.0 * sin_v;
        ld h_vy = h / 2.0 * cos_v;

        Point center = {x, y};
        Point vec_w = {w_vx, w_vy};
        Point vec_h = {h_vx, h_vy};

        all_corners.push_back({center.x + vec_w.x + vec_h.x, center.y + vec_w.y + vec_h.y});
        all_corners.push_back({center.x - vec_w.x + vec_h.x, center.y - vec_w.y + vec_h.y});
        all_corners.push_back({center.x - vec_w.x - vec_h.x, center.y - vec_w.y - vec_h.y});
        all_corners.push_back({center.x + vec_w.x - vec_h.x, center.y + vec_w.y - vec_h.y});
    }

    vector<Point> hull = convex_hull(all_corners);
    ld hull_area = polygon_area(hull);

    ld ratio = 0.0;
    if (hull_area > 1e-9) {
        ratio = (total_board_area / hull_area) * 100.0;
    }

    cout << fixed << setprecision(1) << ratio << " %" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
