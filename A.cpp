#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    ld a, b, n;
    cin >> a >> b >> n;

    if (n > a / b) {
        if (abs(a - b) < 1e-9) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    } else {
        cout << 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
