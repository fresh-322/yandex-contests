#include<bits/stdc++.h>
using namespace std;

bool cycle = true;
vector<vector<int>> g;
vector<int> used;
deque<int> topsort;
void dfs(int v) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to);
        } else if (used[to] == 1) {
            cycle = false;
        }
    }
    topsort.push_front(v);
    used[v] = 2;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n, false);
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;

        g[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }

    if (cycle) {
        for (auto i : topsort) {
            cout << i + 1 << ' ';
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
