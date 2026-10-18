#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<vector<int>> rev_g;
vector<bool> used;
vector<int> ts;
int cnt;
vector<int> col;

void dfs_ts(int v) {
    used[v] = true;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs_ts(to);
        }
    }
    ts[cnt--] = v;
}

void dfs_kss(int v, int c) {
    used[v] = true;
    col[v] = c;
    for (auto to : rev_g[v]) {
        if (!used[to]) {
            dfs_kss(to, c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    g.resize(n);
    rev_g.resize(n);
    used.resize(n, false);
    ts.resize(n);
    col.resize(n);
    cnt = n - 1;

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
    used.assign(n, false);
    int color = 0;
    for (auto i : ts) {
        if (!used[i]) {
            dfs_kss(i, ++color);
        }
    }

    vector<int> ans(color, 0);
    for (int i = 0; i < n; ++i) {
        if (ans[col[i] - 1] < 2) {
            ans[col[i] - 1]++;
        }
    }
    int result = 0;
    for (auto i : ans) result += i;
    cout << result;



    return 0;
}
