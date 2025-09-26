#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> c(n);

    ll sum_odd = 0;
    bool pos_odd = false;
    ll max_odd_val = -3e18;

    ll sum_even = 0;
    bool pos_even = false;
    ll max_even_val = -3e18;

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if ((i + 1) % 2 != 0) { // Odd positions (1-based)
            max_odd_val = max(max_odd_val, c[i]);
            if (c[i] > 0) {
                pos_odd = true;
                sum_odd += c[i];
            }
        } else { // Even positions (1-based)
            max_even_val = max(max_even_val, c[i]);
            if (c[i] > 0) {
                pos_even = true;
                sum_even += c[i];
            }
        }
    }

    ll final_odd_sum = pos_odd ? sum_odd : max_odd_val;

    if (n == 1) {
        cout << final_odd_sum << endl;
        return;
    }

    ll final_even_sum = pos_even ? sum_even : max_even_val;

    cout << max(final_odd_sum, final_even_sum) << endl;
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