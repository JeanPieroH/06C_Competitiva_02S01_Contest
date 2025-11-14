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
        if (c == 'a') total_a++;
    }
    int total_b = n - total_a;

    // If counts are already equal, no removal is needed.
    if (total_a == total_b) {
        cout << 0 << endl;
        return;
    }

    // The core idea: the difference of ('a' - 'b') in the removed substring
    // must be equal to the total difference of ('a' - 'b') in the original string.
    int total_diff = total_a - total_b;

    // We use a map to store the first index at which we see a particular prefix difference.
    // The difference of a substring s[i..j] is prefix_diff[j] - prefix_diff[i-1].
    map<int, int> seen_diffs;
    seen_diffs[0] = -1; // A prefix of length 0 (before the string) has a difference of 0 at index -1.

    int current_diff = 0;
    int min_len = n + 1; // Initialize with a value larger than any possible length.

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            current_diff++;
        } else {
            current_diff--;
        }

        // We are looking for a previous prefix ending at index j, where s[j+1...i] is our substring.
        // We need: current_diff - prev_diff == total_diff.
        // So, the previous difference we are looking for is:
        int target_prev_diff = current_diff - total_diff;

        if (seen_diffs.count(target_prev_diff)) {
            // If we found such a previous prefix, calculate the length of the substring.
            int prev_index = seen_diffs[target_prev_diff];
            min_len = min(min_len, i - prev_index);
        }

        // Store the first time we encounter a new prefix difference.
        if (seen_diffs.find(current_diff) == seen_diffs.end()) {
            seen_diffs[current_diff] = i;
        }
    }

    // If the minimum length found is the entire string, it means we have to remove everything.
    // The problem specifies that in this case, we should output -1.
    // Also handles the case where no solution was found (min_len remains n+1).
    if (min_len >= n) {
        cout << -1 << endl;
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
