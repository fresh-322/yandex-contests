#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> p_f(string s) {
    int n = (int)s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0) {
            if (s[j] == s[i]) break;
            j = p[j - 1];
        }
        p[i] = j + (s[i] == s[j]);
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    string g; cin >> g;
    vector<int> p = p_f(g);
    int j = 0;
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        char x; cin >> x;
        while (j > 0 && g[j] != x) {
            j = p[j - 1];
        }
        if (g[j] == x) {
            j++;
        }
        if (j == n) {
            ans += i - n + 1;
            j = p[j - 1];
        }
    }

    cout << ans;


    return 0;
}
