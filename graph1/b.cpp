#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);

    for (int i = 0;  i < m; ++i) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        a[i] = {v, u};
    }

    vector<int> ts(n + 1);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        ts[--temp] = i;
    }
    bool correct = true;
    for (auto [v, u] : a) {
        if (ts[v] > ts[u]) {
            correct = false;
        }
    }

    if (correct) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
