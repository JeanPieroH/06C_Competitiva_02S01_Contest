#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int dp[3001][3001];

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string w;
        cin >> w;
        int n = w.length();

        if (n <= 1) {
            cout << 0 << endl;
            continue;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = 0;
            }
        }

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (w[i] == w[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = 1 + min({dp[i+1][j], dp[i][j-1], dp[i+1][j-1]});
                }
            }
        }
        cout << dp[0][n-1] << endl;
    }
}

int main() {
    solve();
    return 0;
}