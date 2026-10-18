#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> g;
vector<bool> used;
vector<string> dir;
vector<pair<int, int>> e;


void dfs(int v) {
    used[v] = true;
    for (auto [to, i] : g[v]) {
        if (dir[i] == "None") {
            if (e[i].first == v) {
                dir[i] = "->";
            } else {
                dir[i] = "<-";
            }
        }
        if (!used[to]) dfs(to);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    dir.resize(m, "None");
    g.resize(n);
    e.resize(m);
    used.resize(n, false);
    for (int i = 0; i < m; ++i) {
        int v, u; cin >> v >> u; v--; u--;
        e[i] = {v, u};
    }
    vector<int> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < m; ++i) {
        auto [v, u] = e[i];
        if (c[v] > c[u]) {
            dir[i] = "->";
        } else if (c[v] < c[u]) {
            dir[i] = "<-";
        } else {
            g[v].push_back({u, i});
            g[u].push_back({v, i});
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    for (auto i : dir) cout << i << '\n';


    return 0;
}
