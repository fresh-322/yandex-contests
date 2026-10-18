#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge {
    int from, to;
    ll w;
};

vector<vector<pair<int, int>>> g;
vector<bool> used;
vector<ll> dp;


void dfs(int v) {
    used[v] = true;
    int cnt = 0;
    for (auto [to, w] : g[v]) {
        if (!used[to]) {
            dfs(to);
            cnt += dp[to] + 1;
        }
    }
    dp[v] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    g.resize(n);
    used.resize(n, false);
    dp.resize(n, 0);
    vector<edge> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int v, u, w; cin >> v >> u >> w; v--; u--;
        edges[i] = (edge){v, u, w};
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    dfs(0);
    ll ans = 0;
    for (auto [v, u, w] : edges) {
        int leaf;
        if (dp[v] > dp[u]) {
            leaf = u;
        } else {
            leaf = v;
        }
        ans += w * (dp[leaf] + 1) * (dp[0] - dp[leaf]) * 2;
    }
    cout << ans;

    return 0;
}
