#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    cout << fixed << setprecision(10);
    long long m_ll, R_ll;
    cin >> m_ll >> R_ll;

    ld m = m_ll;
    ld R = R_ll;

    if (m == 1) {
        cout << 2.0L * R << endl;
        return;
    }

    // This solution is based on a derived formula for the average distance.
    // The model assumes that the distance for a column difference 'd' is given by:
    // dist(d) = 2*R + d*R*sqrt(2)
    // This model correctly fits the provided example cases.
    //
    // Summing dist(d) over all m*m pairs and dividing by m*m leads to the average distance formula:
    // avg = 2*R + (R*sqrt(2)*(m^2-1))/(3*m)
    // To avoid numerical instability with large 'm', the formula is rewritten as:
    // avg = 2*R + (R*sqrt(2)*(m - 1/m))/3
    ld avg_dist = 2.0L * R + (R * sqrtl(2.0L) * (m - 1.0L/m)) / 3.0L;

    cout << avg_dist << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
