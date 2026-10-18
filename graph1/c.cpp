#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<vector<int>> rev_g;
vector<int> used;
vector<int> ts;

void dfs_ts(int v) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs_ts(to);
        }
    }
    ts.push_back(v);
}

void dfs_col(int v, int c) {
    used[v] = c;
    for (auto to : rev_g[v]) {
        if (!used[to]) {
            dfs_col(to, c);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    rev_g.resize(n);
    used.resize(n, 0);

    for (int i = 0; i < m; ++i) {
        int v, u; cin >> v >> u; v--; u--;

        g[v].push_back(u);
        rev_g[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs_ts(i);
        }
    }
    used.assign(n, 0);
    int col = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (!used[ts[i]]) {
            dfs_col(ts[i], col++);
        }
    }
    cout << col - 1 << '\n';
    for (int i = 0; i < n; ++i) {
        cout << used[i] << ' ';
    }
    cout << '\n';


    return 0;
}
