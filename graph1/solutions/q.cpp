#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<int> ts;
int cnt;
void dfs(int v) {
    used[v] = true;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    ts[cnt--] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    g.resize(n);
    used.resize(n);
    ts.resize(n);
    cnt = n - 1;
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; ++i) {
        int v, u; cin >> v >> u; v--; u--;
        e[i] = {v, u};
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    set<pair<int, int>> need_e;
    for (int i = 0; i < n - 1; ++i) {

        need_e.insert({ts[i], ts[i + 1]});
    }
    for (int i = 0; i < m; ++i) {
        need_e.erase(e[i]);
        if (need_e.empty()) {
            cout << i + 1;
            break;
        }
    }
    if (!need_e.empty()) {
        cout << -1;
    }
    return 0;
}
