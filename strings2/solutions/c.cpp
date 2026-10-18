#include<bits/stdc++.h>
using namespace std;
using ll = long long;
mt19937_64 rnd(clock());



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<unsigned long long> p(n);
    vector<unsigned long long> h(n);
    for (int i = 0; i < n; ++i) {
        p[i] = rnd();
    }
    for (int i = 0; i < m; ++i) {
        int v, u; cin >> v >> u; v--; u--;
        h[v] += p[u];
        h[u] += p[v];
    }
    long long ans = 0;
    unordered_map<unsigned long long, long long> mp1, mp2;
    mp1.reserve(2 * n);
    mp2.reserve(2 * n);
    for (int i = 0; i < n; ++i) {
        ans += mp1[h[i]]++;
        ans += mp2[h[i] + p[i]]++;
    }
    cout << ans;


    return 0;
}
