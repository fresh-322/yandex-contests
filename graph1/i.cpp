#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, k;
vector<vector<int>> g;
vector<ll> a;
vector<int> used;
deque<int> ts;
vector<ll> dp;
int cnt;
bool cycle;


void dfs_ts(int v, ll w) {
    used[v] = 1;

    for (auto to : g[v]) {
        if (a[to] <= w) {
            if (!used[to]) {
                dfs_ts(to, w);
            }
            if (used[to] == 1) {
                cycle = true;
            }
        }
    }
    ts.push_front(v);
    used[v] = 2;
}

void dfs_ans(int v, ll w) {
    used[v] = 1;
    dp[v] = 0;
    for (auto to : g[v]) {
        if (!used[to] && a[to] <= w) {
            dfs_ans(to, w);
        }
        dp[v] = max(dp[v], dp[to] + 1);
    }
}



bool check(long long w) {
    cycle = false;
    cnt = n - 1;
    used.assign(n, 0);
    ts.clear();
    for (int i = 0; i < n; ++i) {
        if (!used[i] && a[i] <= w) {
            dfs_ts(i, w);
        }
    }
    if (cycle) {
        return true;
    }
    dp.assign(n, -1);
    used.assign(n, 0);
    for (auto i : ts) {
        if (!used[i] && a[i] <= w) {
            dfs_ans(i, w);
        }
    }
    ll ans = -1;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i]);
    }
    return (ans >= k - 1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    g.resize(n);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int v, u; cin >> v >> u; v--; u--;
        g[v].push_back(u);
    }

    ll l = 0, r = 1e18, m;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    if (check(r)) {
        cout << r;
    } else {
        cout << -1;
    }



    return 0;
}
