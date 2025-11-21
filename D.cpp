#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct Point {
    ll x, y;
};

void solve() {
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    if (n % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    ll sum_x = p[0].x + p[n / 2].x;
    ll sum_y = p[0].y + p[n / 2].y;

    for (int i = 1; i < n / 2; ++i) {
        if (p[i].x + p[i + n / 2].x != sum_x || p[i].y + p[i + n / 2].y != sum_y) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    solve();
    return 0;
}
