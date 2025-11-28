#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int ones_a = 0;
    for (char c : a) {
        if (c == '1') {
            ones_a++;
        }
    }
    int ones_b = 0;
    for (char c : b) {
        if (c == '1') {
            ones_b++;
        }
    }

    int diffs = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            diffs++;
        }
    }
    int sames = n - diffs;

    int cost_even = INT_MAX;
    if (ones_a == ones_b) {
        cost_even = diffs;
    }

    int cost_odd = INT_MAX;
    if (ones_a + ones_b == n + 1) {
        cost_odd = sames;
    }

    int ans = min(cost_even, cost_odd);

    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
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
