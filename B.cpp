#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    int roads_to_cross = 0;
    for (int i = 0; i < n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll val1 = a * x1 + b * y1 + c;
        ll val2 = a * x2 + b * y2 + c;
        if ((val1 > 0 && val2 < 0) || (val1 < 0 && val2 > 0)) {
            roads_to_cross++;
        }
    }
    cout << roads_to_cross << endl;
}

int main() {
    solve();
    return 0;
}
