#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    ll n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    ll low = 1, high = 2000000000;
    ll s = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (mid == 0) { // Should not happen with low=1
             low = mid + 1;
             continue;
        }
        unsigned __int128 p = (unsigned __int128)mid * mid;
        if (p >= n) {
            s = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << s - 1 << endl;
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