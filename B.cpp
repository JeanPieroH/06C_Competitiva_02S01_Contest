#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

ll power(ll base, ll exp) {
    ll res = 1;
    ll mod = 1e9 + 7;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll initial_sum = 0;
    ll mod = 1e9 + 7;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        initial_sum += a[i];
    }

    ll max_so_far = 0;
    ll current_max = 0;
    for (ll x : a) {
        current_max += x;
        if (current_max < 0) {
            current_max = 0;
        }
        max_so_far = max(max_so_far, current_max);
    }

    ll max_sub_sum_mod = max_so_far % mod;

    ll pow2k = power(2, k);

    ll added_sum = (max_sub_sum_mod * (pow2k - 1 + mod)) % mod;

    ll final_sum = (initial_sum % mod + mod) % mod;
    final_sum = (final_sum + added_sum) % mod;

    cout << final_sum << endl;
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