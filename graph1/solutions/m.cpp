#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<vector<long long>> dp;
vector<int> need;

void dfs(int v) {
    used[v] = true;
    vector<int> kids;
    for (auto to : g[v]) {
        if (!used[to]) {
            kids.push_back(to);
            dfs(to);
            dp[v][0] += dp[to][1];
            dp[v][1] += min(dp[to][1], dp[to][0]);
        }
    }
}

void dfs_ans(int v) {
    used[v] = true;
    for (auto to : g[v]) {
        if (!used[to]) {
            if (need[v]) {
                if (dp[to][1] <= dp[to][0]) {
                    need[to] = 1;
                }
            } else {
                need[to] = 1;
            }
            dfs_ans(to);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    g.resize(n);
    used.resize(n, false);
    dp.resize(n, vector<long long> (2));
    need.resize(n, 0);

    for (int i = 0; i < n - 1; ++i) {
        int v, u; cin >> v >> u; v--; u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        cin >> dp[i][1];
    }
    if (n > 1) {
        dfs(0);
        cout << min(dp[0][0], dp[0][1]) << ' ';;
        need[0] = dp[0][1] <= dp[0][0];
        used.assign(n, false);
        dfs_ans(0);

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (need[i]) {
                ans.push_back(i);
            }
        }

        cout << ans.size() << '\n';
        for (auto i : ans) {
            cout << i + 1 << ' ';
        }
    } else {
        cout << dp[0][1] << " 1\n1";
    }#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<vector<long long>> dp;
vector<int> need;

void dfs(int v) {
    used[v] = true;
    vector<int> kids;
    for (auto to : g[v]) {
        if (!used[to]) {
            kids.push_back(to);
            dfs(to);
            dp[v][0] += dp[to][1];
            dp[v][1] += min(dp[to][1], dp[to][0]);
        }
    }
}

void dfs_ans(int v) {
    used[v] = true;
    for (auto to : g[v]) {
        if (!used[to]) {
            if (need[v]) {
                if (dp[to][1] <= dp[to][0]) {
                    need[to] = 1;
                }
            } else {
                need[to] = 1;
            }
            dfs_ans(to);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    g.resize(n);
    used.resize(n, false);
    dp.resize(n, vector<long long> (2));
    need.resize(n, 0);

    for (int i = 0; i < n - 1; ++i) {
        int v, u; cin >> v >> u; v--; u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        cin >> dp[i][1];
    }
    if (n > 1) {
        dfs(0);
        cout << min(dp[0][0], dp[0][1]) << ' ';;
        need[0] = dp[0][1] <= dp[0][0];
        used.assign(n, false);
        dfs_ans(0);

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (need[i]) {
                ans.push_back(i);
            }
        }

        cout << ans.size() << '\n';
        for (auto i : ans) {
            cout << i + 1 << ' ';
        }
    } else {
        cout << dp[0][1] << " 1\n1";
    }





    return 0;
}






    return 0;
}
