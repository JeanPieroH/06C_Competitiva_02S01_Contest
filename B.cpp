#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    string s, p;
    cin >> s >> p;

    int n = s.length();
    int m = p.length();

    if (m > n) {
        cout << 0 << endl;
        return;
    }

    vector<int> lps(m, 0);
    int length = 0;
    int i = 1;
    while (i < m) {
        if (p[i] == p[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    int count = 0;
    int j = 0;
    i = 0;
    while (i < n) {
        if (p[j] == s[i]) {
            i++;
            j++;
        }

        if (j == m) {
            count++;
            j = lps[j - 1];
        } else if (i < n && p[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
