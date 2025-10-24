#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    int n;
    cin >> n;

    map<string, int> name_to_id;
    vector<string> id_to_name(n);
    for (int i = 0; i < n; ++i) {
        cin >> id_to_name[i];
        name_to_id[id_to_name[i]] = i;
    }

    int m;
    cin >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        string u, v;
        cin >> u >> v;
        int u_id = name_to_id[u];
        int v_id = name_to_id[v];
        adj[u_id].push_back(v_id);
        adj[v_id].push_back(u_id);
    }

    vector<int> color(n, -1);
    bool is_bipartite = true;
    vector<string> walter_items;
    vector<string> jesse_items;

    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        is_bipartite = false;
                        break;
                    }
                }
                if (!is_bipartite) break;
            }
        }
        if (!is_bipartite) break;
    }

    if (!is_bipartite) {
        cout << "impossible" << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                walter_items.push_back(id_to_name[i]);
            } else {
                jesse_items.push_back(id_to_name[i]);
            }
        }
        for (size_t i = 0; i < walter_items.size(); ++i) {
            cout << walter_items[i] << (i == walter_items.size() - 1 ? "" : " ");
        }
        cout << endl;
        for (size_t i = 0; i < jesse_items.size(); ++i) {
            cout << jesse_items[i] << (i == jesse_items.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
