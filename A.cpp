#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    for (int k = 0; k <= n; ++k) {
        if (k == n) {
            cout << n << endl;
            return;
        }
        ll required_suffix = (1LL << (n - k)) - 1;
        ll suffix_mask = required_suffix;

        if (((x & suffix_mask) == required_suffix) && ((y & suffix_mask) == required_suffix)) {
            cout << k << endl;
            return;
        }
    }
}

int main() {
    solve();
    return 0;
}