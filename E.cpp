#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    vector<int> lps(n, 0);
    int length = 0;
    int i = 1;
    while (i < n) {
        if (s[i] == s[length]) {
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

    vector<int> counts(n + 1, 0);
    for (int i = 0; i < n; i++) {
        counts[lps[i]]++;
    }

    for (int i = n - 1; i > 0; i--) {
        counts[lps[i - 1]] += counts[i];
    }

    for(int i = 0; i <= n; i++){
        counts[i]++;
    }


    vector<pair<int, int>> result;
    int current_lps = lps[n - 1];
    while (current_lps > 0) {
        result.push_back({current_lps, counts[current_lps]});
        current_lps = lps[current_lps - 1];
    }
    result.push_back({n, counts[n]});


    sort(result.begin(), result.end());

    cout << result.size() << endl;
    for (auto const& [len, count] : result) {
        cout << len << " " << count << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
