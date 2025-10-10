#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    bool failed = false;
    for (int i = 0; i < 8; ++i) {
        int bit;
        cin >> bit;
        if (bit == 9) {
            failed = true;
        }
    }
    if (failed) {
        cout << "F" << endl;
    } else {
        cout << "S" << endl;
    }
}

int main() {
    solve();
    return 0;
}