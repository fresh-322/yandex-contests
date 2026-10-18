#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<pair<int, ll>>> g;
vector<bool> used;
vector<ll> dp;
vector<int> s;
vector<ll> ans;


void dfs_dp(int v) {
    used[v] = true;
    for (auto [to, w] : g[v]) {
        if (!used[to]) {
            dfs_dp(to);
            dp[v] += w * (s[to]) + dp[to];
            s[v] += s[to];
        }
    }
}

void dfs_ans(int v) {
    used[v] = true;
    for (auto [to, w] : g[v]) {
        if (!used[to]) {
            ans[to] = ans[v] - w * s[to] + w * (n - s[to]);
            dfs_ans(to);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g.resize(n);
    used.resize(n, false);
    dp.resize(n);
    ans.resize(n);
    s.resize(n, 1);

    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        ll w; cin >> v >> u >> w; v--; u--;
        g[v].emplace_back(u, w);
        g[u].emplace_back(v, w);
    }
    dfs_dp(0);
    ans[0] = dp[0];
    used.assign(n, false);
    dfs_ans(0);
    for (auto i : ans) cout << i << ' ';

    return 0;
}
