#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<bool> used;
vector<int> p;
vector<ll> t;
vector<ll> ans;

void dfs(int v) {
    used[v] = true;

    for (auto to : g[v]) {
        if (!used[to]) {
            p[to] = v;
            dfs(to);
            t[v] += t[to];
        }
    }
}

void dfs_ans(int v) {
    used[v] = true;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs_ans(to);
        }
    }
    ans.push_back(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    g.resize(n);
    used.resize(n, false);
    p.resize(n, -1);

    t.resize(n);

    for (int i = 0; i < n; ++i) cin >> t[i];

    for (int i = 0;  i < n; ++i) {
        int req; cin >> req;
        for (int j = 0; j < req; ++j) {
            int u; cin >> u; u--;
            g[i].push_back(u);
        }
    }
    dfs(0);
    cout << t[0] << ' ';
    used.assign(n, false);
    dfs_ans(0);
    cout << ans.size();
    cout << '\n';
    for (auto i : ans) cout << i + 1 << ' ';








    return 0;
}
