#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    int n, w;
    cin >> n >> w;

    if (w > n) {
        cout << 0 << endl;
        return;
    }

    if (w == 1) {
        cout << n << endl;
        return;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(w);
    for (int i = 0; i < w; ++i) {
        cin >> b[i];
    }

    vector<int> diff_a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        diff_a[i] = a[i+1] - a[i];
    }

    vector<int> diff_b(w - 1);
    for (int i = 0; i < w - 1; ++i) {
        diff_b[i] = b[i+1] - b[i];
    }

    vector<int> lps(w - 1, 0);
    int length = 0;
    int i = 1;
    while (i < w - 1) {
        if (diff_b[i] == diff_b[length]) {
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
    while (i < n - 1) {
        if (diff_b[j] == diff_a[i]) {
            i++;
            j++;
        }

        if (j == w - 1) {
            count++;
            j = lps[j - 1];
        } else if (i < n - 1 && diff_b[j] != diff_a[i]) {
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
