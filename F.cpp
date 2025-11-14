#include <iostream>
#include <vector>
#include <string>

void solve() {
    int n;
    long long k;
    std::cin >> n >> k;

    if (k == (long long)n * n - 1) {
        std::cout << "NO" << std::endl;
        return;
    }

    std::cout << "YES" << std::endl;
    long long cells_to_trap = (long long)n * n - k;

    if (cells_to_trap == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << 'U';
            }
            std::cout << std::endl;
        }
        return;
    }

    std::vector<std::vector<char>> grid(n, std::vector<char>(n, 'U'));
    long long trapped_count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; j += 2) {
            if (trapped_count < (cells_to_trap / 2) * 2) {
                grid[i][j] = 'R';
                grid[i][j + 1] = 'L';
                trapped_count += 2;
            } else {
                break;
            }
        }
        if (trapped_count == (cells_to_trap / 2) * 2) {
            break;
        }
    }

    if (cells_to_trap % 2 == 1) {
        long long count = 0;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (count == cells_to_trap - 1) {
                    if (i > 0) {
                        grid[i][j] = 'U';
                    } else if (j > 0) {
                        grid[i][j] = 'L';
                    }
                }
                count++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
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
