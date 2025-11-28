#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int MOD = 998244353;
const int MAXN = 300005;
vector<int> adj[MAXN];
int color[MAXN];
bool visited[MAXN];

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        color[i] = 0;
        visited[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ll count1 = 0, count2 = 0;
            bool possible = true;
            queue<int> q;

            q.push(i);
            visited[i] = true;
            color[i] = 1;
            count1++;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        color[v] = 3 - color[u];
                        if (color[v] == 1) count1++;
                        else count2++;
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        possible = false;
                    }
                }
            }
            if (!possible) {
                ans = 0;
                break;
            }
            ll ways = (power(2, count1) + power(2, count2)) % MOD;
            ans = (ans * ways) % MOD;
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
