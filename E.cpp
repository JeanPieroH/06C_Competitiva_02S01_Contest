#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    cout << fixed << setprecision(10);
    double m, R;
    cin >> m >> R;

    if (m == 1) {
        cout << 2.0 * R << endl;
        return;
    }

    double avg_dist = R * ( (4.0 / (3.0 * m)) + (2.0 * m / 3.0) + (1.0 - (1.0 / m)) * sqrt(2.0) );
    cout << avg_dist << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
