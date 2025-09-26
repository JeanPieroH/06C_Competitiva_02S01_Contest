#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

ll cookies_in_gap(ll p1, ll p2, ll d) {
    if (p1 >= p2) return 0;
    return (p2 - p1 - 1) / d;
}

ll cookies_in_final_gap(ll p1, ll n, ll d) {
    if (p1 > n) return 0;
    return (n - p1) / d;
}

void solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> s(m);
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
    }

    // 1. Correct base_cookies calculation
    ll base_cookies = m;
    ll last_eaten = 1;

    if (s[0] != 1) {
        base_cookies++;
    }

    for (int i = 0; i < m; ++i) {
        base_cookies += cookies_in_gap(last_eaten, s[i], d);
        last_eaten = s[i];
    }
    base_cookies += cookies_in_final_gap(last_eaten, n, d);

    // 2. Correct savings calculation
    vector<ll> savings(m);
    for (int i = 0; i < m; ++i) {
        ll current_saving = 0;

        if (i == 0 && s[0] == 1) {
            current_saving = 0; // Removing seller at 1 saves nothing
        } else {
            ll p_before = (i == 0) ? 1 : s[i - 1];
            ll p_current = s[i];

            if (i < m - 1) { // Not the last seller
                ll p_after = s[i + 1];
                current_saving = 1 + cookies_in_gap(p_before, p_current, d) + cookies_in_gap(p_current, p_after, d) - cookies_in_gap(p_before, p_after, d);
            } else { // Last seller
                current_saving = 1 + cookies_in_gap(p_before, p_current, d) + cookies_in_final_gap(p_current, n, d) - cookies_in_final_gap(p_before, n, d);
            }
        }
        savings[i] = current_saving;
    }

    // 3. Find min_cookies and count
    ll max_saving = 0;
    for (ll val : savings) {
        if (val > max_saving) {
            max_saving = val;
        }
    }

    ll min_total_cookies = base_cookies - max_saving;

    ll count_min = 0;
    if (max_saving > 0) { // Should always be true unless no savings possible
        for (ll val : savings) {
            if (val == max_saving) {
                count_min++;
            }
        }
    } else { // Case where no removal can save any cookie
        count_min = m;
    }


    cout << min_total_cookies << " " << count_min << endl;
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