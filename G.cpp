#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const ll INF = 4e18; // A large enough value for infinity

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[0] << endl;
        return;
    }

    vector<ll> b(n), c(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] - 2LL * i;
        c[i] = a[i] + 2LL * i;
    }

    vector<ll> prefix_max_b(n);
    prefix_max_b[0] = b[0];
    for (int i = 1; i < n; ++i) {
        prefix_max_b[i] = max(prefix_max_b[i - 1], b[i]);
    }

    vector<ll> suffix_max_c(n);
    suffix_max_c[n - 1] = c[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffix_max_c[i] = max(suffix_max_c[i + 1], c[i]);
    }

    ll min_x = INF;

    for (int i = 0; i < n; ++i) {
        ll val_L = -INF;
        if (i > 0) {
            val_L = 2LL * i + prefix_max_b[i - 1];
        }

        ll val_R = -INF;
        if (i < n - 1) {
            val_R = -2LL * i + suffix_max_c[i + 1];
        }

        ll current_x = a[i];
        if (val_L > -INF) current_x = max(current_x, val_L);
        if (val_R > -INF) current_x = max(current_x, val_R);

        min_x = min(min_x, current_x);
    }

    cout << min_x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve(); // Problem G has only one test case per run
    return 0;
}