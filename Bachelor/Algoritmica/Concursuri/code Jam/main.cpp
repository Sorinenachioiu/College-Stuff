#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int n;
    cin >> n;
    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }
    map<int, int> color_map;
    set<int> used;
    int next_int = 1;
    for (int color : colors) {
        if (color_map.find(color) == color_map.end()) {
            while (used.find(next_int) != used.end()) {
                next_int++;
            }
            color_map[color] = next_int;
            used.insert(next_int);
        }
        else {
            color_map[color] = max(color_map[color], next_int);
            if (color_map[color] > next_int) {
                cout << "Case #" << t << ": IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    cout << "Case #" << t << ":";
    for (auto p : color_map) {
        cout << " " << p.first;
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
    return 0;
}
