#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    string s;
    cin >> s;
    string target = "hello";
    int j = 0; // Pointer for the target string
    for (int i = 0; i < s.length(); ++i) {
        if (j < target.length() && s[i] == target[j]) {
            j++;
        }
    }

    if (j == target.length()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // The problem description implies a single test case.
    solve();
    return 0;
}