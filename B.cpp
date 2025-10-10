#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arrows_at_height(1000002, 0);
    int arrows_shot = 0;

    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        if (arrows_at_height[h] > 0) {
            arrows_at_height[h]--;
            if (h > 0) {
                arrows_at_height[h - 1]++;
            }
        } else {
            arrows_shot++;
            if (h > 0) {
                arrows_at_height[h - 1]++;
            }
        }
    }
    cout << arrows_shot << endl;
}

int main() {
    solve();
    return 0;
}