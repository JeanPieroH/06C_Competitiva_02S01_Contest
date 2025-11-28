#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    ll x5, y5, x6, y6;
    cin >> x5 >> y5 >> x6 >> y6;

    auto intersection_area = [&](ll X1, ll Y1, ll X2, ll Y2, ll X3, ll Y3, ll X4, ll Y4) {
        ll x_overlap = max(0LL, min(X2, X4) - max(X1, X3));
        ll y_overlap = max(0LL, min(Y2, Y4) - max(Y1, Y3));
        return x_overlap * y_overlap;
    };

    auto total_area = (x2 - x1) * (y2 - y1);
    auto black1_area = intersection_area(x1, y1, x2, y2, x3, y3, x4, y4);
    auto black2_area = intersection_area(x1, y1, x2, y2, x5, y5, x6, y6);

    ll x_overlap_black = max(0LL, min({x2, x4, x6}) - max({x1, x3, x5}));
    ll y_overlap_black = max(0LL, min({y2, y4, y6}) - max({y1, y3, y5}));
    ll common_area = x_overlap_black * y_overlap_black;

    if (total_area > black1_area + black2_area - common_area) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    solve();
    return 0;
}
