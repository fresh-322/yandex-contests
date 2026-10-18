#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;


const int mod = 1e9 + 7;
struct hash_t {
    int x;
    ull y;

    hash_t(int v1 = 0, ull v2 = 0) {
        x = v1; y = v2;
    }
    hash_t operator+(const hash_t& other) const {
        if (0ll + x + other.x >= mod) return hash_t(0ll + x + other.x - mod, y + other.y);
        return hash_t(x + other.x, y + other.y);
    }
    hash_t operator-(const hash_t& other) const {
        if (0ll + x - other.x < 0) return hash_t(0ll + x - other.x + mod, y - other.y);
        return hash_t(x - other.x, y - other.y);
    }
    hash_t operator*(const hash_t& other) const {
        return hash_t(1ll * x * other.x % mod, y * other.y);
    }
    bool operator==(const hash_t& other) const {
        return (x == other.x && y == other.y);
    }
};

vector<int> z_f(string p, string s) {
    string str = p + '#' + s;
    vector<int> z(str.size(), 0);
    int l = 0, r = 0;
    z[0] = (int)str.size();
    for (int i = 1; i < (int)str.size(); ++i) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < (int)str.size() && str[i + z[i]] == str[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    vector<int> ans;
    for (int i = (int)p.size() + 1; i < (int)str.size(); ++i) {
        ans.push_back(z[i]);
    }
    return ans;
}
hash_t base = hash_t(31, 31);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string p, s; cin >> p >> s;
    int n = s.size(), m = p.size();
    vector<hash_t> hs(n + 1), hp(m + 1), pp(n + 1);
    pp[0] = hash_t(1, 1);
    for (int i = 0; i < n; ++i) {
        hs[i + 1] = hs[i] * base + hash_t(s[i] - 'a' + 1, s[i] - 'a' + 1);
        pp[i + 1] = pp[i] * base;
    }
    for (int i = 0; i < m; ++i) {
        hp[i + 1] = hp[i] * base + hash_t(p[i] - 'a' + 1, p[i] - 'a' + 1);
    }
    pp[0] = hash_t(1, 1);
    vector<int> z = z_f(p, s);

    vector<int> ans;
    for (int i = 0; i < n - m + 1; ++i) {
        if (z[i] == m || z[i] == m - 1) {
            ans.push_back(i + 1);
            continue;
        }
        hash_t a = hp[m] - hp[z[i] + 1] * pp[m - z[i] - 1], b = hs[i + m] - hs[i + z[i] + 1] * pp[m - z[i] - 1];
        if (a == b) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';

    return 0;
}
