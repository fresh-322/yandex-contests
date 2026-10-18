#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> g1, g2;
map<vector<int>, ll> mp;

int hash_dfs(int v, int p, vector<vector<int>>& g) {
    vector<int> kids;
    for (auto to : g[v]) {
        if (to != p) {
            kids.push_back(hash_dfs(to, v, g));
        }
    }
    sort(kids.begin(), kids.end());
    auto it = mp.find(kids);
    if (it != mp.end()) {
        return it->second;
    }
    mp[kids] = mp.size();
    return mp.size() - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int r1, r2; cin >> r1 >> r2; r1--; r2--;
    g1.resize(n);
    g2.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int v, u; cin >> v >> u; v--; u--;
        g1[v].push_back(u);
        g1[u].push_back(v);
    }
    for (int i = 0; i < n - 1; ++i) {
        int v, u; cin >> v >> u; v--; u--;
        g2[v].push_back(u);
        g2[u].push_back(v);
    }
    if (hash_dfs(r1, -1, g1) == hash_dfs(r2, -1, g2)) {
        cout << "YES";
    } else {
        cout << "NO";
    }




    return 0;
}
