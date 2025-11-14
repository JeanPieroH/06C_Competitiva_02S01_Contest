#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    // A solution is impossible if and only if we need to trap exactly n*n - 1 cells.
    // A single remaining cell cannot form a cycle on its own and must point to the border,
    // thus escaping. Any other number of cells can be trapped.
    if (k == (ll)n * n - 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector<vector<char>> grid(n, vector<char>(n, 'U'));
    ll cells_to_trap = (ll)n * n - k;

    // If no cells need to be trapped, all cells can point Up ('U') to escape.
    if (cells_to_trap == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << 'U';
            }
            cout << endl;
        }
        return;
    }

    // To trap cells, we form simple horizontal cycles of two.
    // A cell points Right ('R') into a cell that points Left ('L').
    // We fill these pairs starting from the top-left of the grid.
    ll trapped_pairs_to_create = cells_to_trap / 2;
    ll pairs_created = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; j += 2) {
            if (pairs_created < trapped_pairs_to_create) {
                grid[i][j] = 'R';
                grid[i][j + 1] = 'L';
                pairs_created++;
            } else {
                break;
            }
        }
        if (pairs_created == trapped_pairs_to_create) {
            break;
        }
    }

    // If there's an odd number of cells to trap, one cell remains.
    // We place it at the next available grid position.
    // To ensure it's trapped, it must point to an already trapped cell.
    if (cells_to_trap % 2 == 1) {
        ll last_trap_cell_index = cells_to_trap - 1;
        int r = last_trap_cell_index / n;
        int c = last_trap_cell_index % n;

        // If the last cell is not in the first row, pointing 'U' leads to a trapped cell above.
        // If it is in the first row (r=0), it must have a trapped cell to its left (since c > 0,
        // as the k=n*n-1 case for (0,0) is impossible), so we point 'L'.
        if (r > 0) {
            grid[r][c] = 'U';
        } else if (c > 0) {
            grid[r][c] = 'L';
        }
        // The case (r=0, c=0) for the single odd cell only happens if cells_to_trap=1,
        // which means k=n*n-1, a case we've already handled.
    }

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
