#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <map>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int total_a = 0;
    int total_b = 0;
    for (char c : s) {
        if (c == 'a') {
            total_a++;
        } else {
            total_b++;
        }
    }

    if (total_a == total_b) {
        std::cout << 0 << std::endl;
        return;
    }

    if (total_a == 0 || total_b == 0) {
        std::cout << -1 << std::endl;
        return;
    }

    int diff = total_a - total_b;
    std::map<int, int> prefix_diff_map;
    prefix_diff_map[0] = -1;
    int current_diff = 0;
    int min_len = n;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            current_diff++;
        } else {
            current_diff--;
        }

        if (prefix_diff_map.count(current_diff - diff)) {
            min_len = std::min(min_len, i - prefix_diff_map[current_diff - diff]);
        }

        if (prefix_diff_map.find(current_diff) == prefix_diff_map.end()) {
            prefix_diff_map[current_diff] = i;
        }
    }

    if (min_len == n) {
       std::cout << -1 << std::endl;
    } else {
       std::cout << min_len << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
