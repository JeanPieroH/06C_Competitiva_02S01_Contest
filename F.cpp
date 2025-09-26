#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n;
    cin >> n;
    set<ll> unique_elements;
    for (int i = 0; i < n; ++i) {
        ll val;
        cin >> val;
        unique_elements.insert(val);
    }

    vector<ll> u(unique_elements.begin(), unique_elements.end());

    if (u.empty()) {
        cout << 0 << endl;
        return;
    }

    int max_len = 0;
    int l = 0;
    for (int r = 0; r < u.size(); ++r) {
        while (u[r] - u[l] > n - 1) {
            l++;
        }
        max_len = max(max_len, r - l + 1);
    }
    cout << max_len << endl;
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