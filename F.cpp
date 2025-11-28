#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const int MAXN = 1 << 17;
int a[MAXN];
int tree[4 * MAXN];
int n, m;

void build(int node, int start, int end, int op) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid, 1 - op);
    build(2 * node + 1, mid + 1, end, 1 - op);
    if (op) {
        tree[node] = tree[2 * node] | tree[2 * node + 1];
    } else {
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }
}

void update(int node, int start, int end, int idx, int val, int op) {
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (start <= idx && idx <= mid) {
        update(2 * node, start, mid, idx, val, 1 - op);
    } else {
        update(2 * node + 1, mid + 1, end, idx, val, 1 - op);
    }
    if (op) {
        tree[node] = tree[2 * node] | tree[2 * node + 1];
    } else {
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }
}

void solve() {
    cin >> n >> m;
    int size = 1 << n;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    build(1, 0, size - 1, n % 2);

    for (int i = 0; i < m; i++) {
        int p, b;
        cin >> p >> b;
        update(1, 0, size - 1, p - 1, b, n % 2);
        cout << tree[1] << endl;
    }
}

int main() {
    solve();
    return 0;
}
