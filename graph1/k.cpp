#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> wp;
vector<vector<int>> rev_wp;
vector<vector<int>> all;
vector<bool> used;
vector<int> out;
vector<int> col;
vector<int> ts;
int cnt;
bool cycle = false;
void dfs_ts(int v) {
    used[v] = true;
    for (auto to : wp[v]) {
        if (!used[to]) {
            dfs_ts(to);
        }
    }
    ts[cnt--] = v;
}
void dfs_kss(int v, int c) {
    used[v] = true;
    col[v] = c;
    for (auto to : rev_wp[v]) {
        if (!used[to]) {
            dfs_kss(to, c);
        }
    }
}
void dfs_ans(int v) {
    used[v] = true;
    if (out[col[v]] && v != 0) {
        cycle = true;
    }
    for (auto to : all[v]) {
        if (!used[to]) {
            dfs_ans(to);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    all.resize(n);
    wp.resize(n);
    col.resize(n);
    rev_wp.resize(n);
    used.resize(n, false);
    ts.resize(n);
    cnt = n - 1;

    for (int i = 0; i < m; ++i) {
        int v, u, type; cin >> v >> u >> type; v--; u--;
        if (type == 2) {
            wp[v].push_back(u);
            rev_wp[u].push_back(v);
        }
        all[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs_ts(i);
        }
    }
    used.assign(n, false);
    int c = 0;
    for (auto i : ts) {
        if (!used[i]) {
            dfs_kss(i, c++);
        }
    }
    out.resize(c);
    for (int i = 0; i < n; ++i) {
        for (auto to : wp[i]) {
            if (col[i] != col[to]) {
                out[col[i]] = true;
            }
        }
    }
    used.assign(n, false);

    dfs_ans(0);
    if (cycle) {
        cout << "Yes";
    } else {
        cout << "No";
    }



    return 0;
}
