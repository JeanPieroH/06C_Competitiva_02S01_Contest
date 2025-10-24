#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<set<char>> adj(26);
    set<char> used_chars;

    if (s.length() > 1) {
        for (size_t i = 0; i < s.length() - 1; ++i) {
            adj[s[i] - 'a'].insert(s[i+1]);
            adj[s[i+1] - 'a'].insert(s[i]);
            used_chars.insert(s[i]);
            used_chars.insert(s[i+1]);
        }
    } else {
        used_chars.insert(s[0]);
    }

    string keyboard = "";
    char start_char = ' ';
    bool possible = true;
    int start_count = 0;

    for (char c : used_chars) {
        if (adj[c - 'a'].size() > 2) {
            possible = false;
            break;
        }
        if (adj[c - 'a'].size() == 1) {
            start_char = c;
            start_count++;
        }
    }

    if (start_count != 2 && s.length() > 1) {
        possible = false;
    }

    if (!possible) {
        cout << "NO" << endl;
        return;
    }

    if (s.length() == 1) {
        keyboard = s;
        start_char = ' ';
    } else {
        if (start_char == ' ') {
             for (char c : used_chars) {
                if (adj[c - 'a'].size() == 2) {
                    bool is_cycle = true;
                    for (char neighbor : adj[c - 'a']) {
                        if (adj[neighbor - 'a'].size() != 2) {
                            is_cycle = false;
                            break;
                        }
                    }
                    if (is_cycle) {
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
             cout << "NO" << endl;
             return;
        }

        string path = "";
        set<char> visited;
        queue<char> q;

        q.push(start_char);
        visited.insert(start_char);

        while(!q.empty()){
            char u = q.front();
            q.pop();
            path += u;
            for(char v : adj[u - 'a']){
                if(visited.find(v) == visited.end()){
                    visited.insert(v);
                    q.push(v);
                }
            }
        }
        if (path.length() != used_chars.size()) {
             cout << "NO" << endl;
             return;
        }
        keyboard = path;
    }


    for (char c = 'a'; c <= 'z'; ++c) {
        if (used_chars.find(c) == used_chars.end()) {
            keyboard += c;
        }
    }

    cout << "YES" << endl;
    cout << keyboard << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
