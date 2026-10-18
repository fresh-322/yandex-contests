#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<bool> used;
vector<vector<pair<int, int>>> g;
vector<int> ts, rev_ts;
vector<int> dist;
int cnt;

void dfs(int v) {
    used[v] = true;
    for (auto [to, w] : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    ts[cnt] = v;
    rev_ts[v] = cnt--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s >> t;
    s--;
    t--;
    g.resize(n);
    used.resize(n, false);
    ts.resize(n);
    rev_ts.resize(n);
    dist.resize(n, 1e9);
    dist[s] = 0;
    cnt = n - 1;

    for (int i = 0; i < m; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        v--;
        u--;

        g[v].push_back({u, w});
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }

    for (int i = rev_ts[s]; i < rev_ts[t]; ++i) {
        if (dist[ts[i]] != 1e9) {
            for (auto [to, w] : g[ts[i]]) {
                dist[to] = min(dist[to], dist[ts[i]] + w);
            }
        }
    }

    if (dist[t] == 1e9) {
        cout << "Unreachable\n";
    } else {
        cout << dist[t] << '\n';
    }






    return 0;
}
