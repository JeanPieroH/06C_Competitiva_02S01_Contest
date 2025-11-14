#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total_a = 0;
    for (char c : s) {
        if (c == 'a') {
            total_a++;
        }
    }
    int total_b = n - total_a;

    if (total_a == total_b) {
        cout << 0 << endl;
        return;
    }

    // Pre-calculate suffix differences and the first index where they appear.
    map<int, int> suffix_diff_map;
    suffix_diff_map[0] = n;
    int a_count = 0, b_count = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'a') a_count++;
        else b_count++;
        if (suffix_diff_map.find(a_count - b_count) == suffix_diff_map.end()) {
            suffix_diff_map[a_count - b_count] = i;
        }
    }

    int min_len = n;

    // Case 1: Remove a prefix.
    // The remaining string is a suffix. We need its a-b diff to be 0.
    int required_suffix_diff = 0;
    if (suffix_diff_map.count(required_suffix_diff)) {
        min_len = min(min_len, suffix_diff_map[required_suffix_diff]);
    }

    // Case 2: Remove a middle part.
    // Iterate through all possible prefixes. For each prefix, find a suffix
    // that balances the counts.
    a_count = 0;
    b_count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') a_count++;
        else b_count++;

        int prefix_diff = a_count - b_count;
        // We need a suffix with a difference of -prefix_diff.
        int target_suffix_diff = -prefix_diff;

        if (suffix_diff_map.count(target_suffix_diff)) {
            int suffix_start_idx = suffix_diff_map[target_suffix_diff];
            if (i < suffix_start_idx) {
                min_len = min(min_len, suffix_start_idx - (i + 1));
            }
        }
    }

    // If min_len is still n, it means we must remove the whole string.
    if (min_len == n) {
        // We can only make counts equal by removing the whole string
        // if the total difference is not zero.
        if (total_a != total_b) {
            cout << -1 << endl;
        } else {
             // This case is handled at the start, but for completeness.
            cout << 0 << endl;
        }
    } else {
        cout << min_len << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
