#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    // The only impossible case is when exactly one cell needs to be a trap.
    // A single cell cannot form a cycle by itself and must point to another cell,
    // which would either lead to an escape or involve another cell in the trap.
    if (k == (ll)n * n - 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector<vector<char>> grid(n, vector<char>(n, 'U'));
    ll cells_to_trap = (ll)n * n - k;

    if (cells_to_trap == 0) {
        // If all cells must be escaping, point them all up.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << 'U';
            }
            cout << endl;
        }
        return;
    }

    // We create traps by forming `R-L` pairs. This creates a simple 2-cell cycle.
    // We fill these pairs from the top-left of the grid.
    ll trapped_pairs = cells_to_trap / 2;
    ll trapped_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; j += 2) {
            if (trapped_count < trapped_pairs) {
                grid[i][j] = 'R';
                grid[i][j + 1] = 'L';
                trapped_count++;
            } else {
                break;
            }
        }
        if (trapped_count == trapped_pairs) {
            break;
        }
    }

    // If there is an odd number of cells to trap, one cell will be left over.
    // We place it at the next available spot and make it point to a previously
    // trapped cell to ensure it doesn't escape.
    if (cells_to_trap % 2 == 1) {
        ll last_trap_idx = cells_to_trap - 1;
        int r = last_trap_idx / n;
        int c = last_trap_idx % n;

        // This cell must point to another trapped cell. Pointing up is safe if not in the first row.
        // If in the first row, pointing left is safe (since it can only be the first cell if k=n*n-1, which is handled).
        if (r > 0) {
            grid[r][c] = 'U';
        } else if (c > 0) {
            grid[r][c] = 'L';
        }
        // Special case for (0,0) is implicitly handled by the k != n*n-1 check.
    }

    // Print the final grid.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
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
