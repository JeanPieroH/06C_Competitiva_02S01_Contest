#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

vector<int> counts(30, 0);

void solve_add(int x) {
    counts[x]++;
}

void solve_get(int w) {
    for (int i = 29; i >= 0; --i) {
        if (w <= 0) break;
        int power_of_2 = 1 << i;
        int num_needed = w / power_of_2;
        int num_to_use = min(counts[i], num_needed);
        w -= num_to_use * power_of_2;
    }

    if (w == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;
    while (m--) {
        int type, val;
        cin >> type >> val;
        if (type == 1) {
            solve_add(val);
        } else {
            solve_get(val);
        }
    }
    return 0;
}