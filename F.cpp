#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    ll x, d;
    cin >> x >> d;
    if (x * 2 > d) {
        cout << "take it" << endl;
    } else {
        cout << "double it" << endl;
    }
}

int main() {
    solve();
    return 0;
}