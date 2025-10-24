#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

vector<int> parent;
vector<int> sz;
vector<long long> edges;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        edges[a] += edges[b];
    }
    edges[a]++;
}

void solve() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);
    sz.assign(n + 1, 1);
    edges.assign(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }

    int cycle_components = 0;
    for (int i = 1; i <= n; ++i) {
        if (parent[i] == i) {
            if (edges[i] == sz[i] && sz[i] >= 3) {
                cycle_components++;
            }
        }
    }

    cout << cycle_components << endl;
}

int main() {
    solve();
    return 0;
}
