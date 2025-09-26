#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    ll n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> x(n);
    map<ll, ll> monster_health;

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> x[i];

    for (int i = 0; i < n; ++i) {
        monster_health[abs(x[i])] += a[i];
    }

    ll bullets_rem = 0;
    ll last_pos = 0;

    for (auto const& [pos, health] : monster_health) {
        ll bullets_needed = health;
        ll time_diff = pos - last_pos;
        ll bullets_gained = time_diff * k;

        bullets_rem += bullets_gained;

        if (bullets_rem < bullets_needed) {
            cout << "NO" << endl;
            return;
        }
        bullets_rem -= bullets_needed;
        last_pos = pos;
    }

    cout << "YES" << endl;
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