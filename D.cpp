#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_len = 0;
    int current_len = 0;
    if (n > 0) {
      max_len = 1;
      current_len = 1;
    }


    for (int i = 1; i < n; ++i) {
        if (a[i] <= a[i - 1] * 2) {
            current_len++;
        } else {
            current_len = 1;
        }
        if (current_len > max_len) {
            max_len = current_len;
        }
    }
    cout << max_len << endl;
}

int main() {
    solve();
    return 0;
}