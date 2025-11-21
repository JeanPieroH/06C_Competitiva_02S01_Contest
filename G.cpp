#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_set<int> x_coords_on_0;
    unordered_set<int> x_coords_on_1;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (y == 0) {
            x_coords_on_0.insert(x);
        } else {
            x_coords_on_1.insert(x);
        }
    }

    ll total_triangles = 0;
    ll n0 = x_coords_on_0.size();
    ll n1 = x_coords_on_1.size();

    // Scenario 1: Axis-aligned triangles
    ll common_count = 0;
    if (n0 > 0 && n1 > 0) {
        for (int x : x_coords_on_0) {
            if (x_coords_on_1.count(x)) {
                common_count++;
            }
        }
    }
    if (common_count > 0) {
        if (n0 > 1) {
            total_triangles += common_count * (n0 - 1);
        }
        if (n1 > 1) {
            total_triangles += common_count * (n1 - 1);
        }
    }

    // Scenario 2: Right angle on one line, other two vertices on the other
    if (n1 >= 2) {
        for (int x_c : x_coords_on_0) {
            if (x_coords_on_1.count(x_c - 1) && x_coords_on_1.count(x_c + 1)) {
                total_triangles++;
            }
        }
    }

    if (n0 >= 2) {
        for (int x_c : x_coords_on_1) {
            if (x_coords_on_0.count(x_c - 1) && x_coords_on_0.count(x_c + 1)) {
                total_triangles++;
            }
        }
    }

    cout << total_triangles << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
