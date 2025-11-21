#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld PI = acos(-1.0L);

void solve() {
    int m;
    cin >> m;

    ld x = 0.0, y = 0.0;
    ld current_angle_deg = 90.0;

    for (int i = 0; i < m; ++i) {
        ld turn_angle, distance;
        cin >> turn_angle >> distance;

        current_angle_deg += turn_angle;
        ld current_angle_rad = current_angle_deg * PI / 180.0L;

        x += distance * cos(current_angle_rad);
        y += distance * sin(current_angle_rad);
    }

    cout << fixed << setprecision(6) << x << " " << y << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
