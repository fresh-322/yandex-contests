#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int mod = 1e9 + 7;

int n;
struct hash_t {
    int x;
    ull y;
    hash_t(int v1 = 0, ull v2 = 0) {
        x = v1; y = v2;
    }
    hash_t operator+(const hash_t other) const {
        if (0ll + other.x + x >= mod) return hash_t(other.x + x - mod, other.y + y);
        return hash_t(x + other.x, y + other.y);
    }
    hash_t operator-(const hash_t other) const {
        if (0ll + x - other.x < 0) return hash_t(x - other.x + mod, y - other.y);
        return hash_t(x - other.x, y - other.y);
    }
    hash_t operator*(const hash_t other) const {
        return hash_t(1ll * x * other.x % mod, y * other.y);
    }
    bool operator==(const hash_t other) const {
        return x == other.x && y == other.y;
    }
};
hash_t base = hash_t(31, 31);

bool check(int x, int r, vector<hash_t>& h, vector<hash_t>& rev_h, vector<hash_t>& p) {
    return h[x + r] - h[x] * p[r] == rev_h[x - r + 1] - rev_h[x + 1] * p[r];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string temp, s = ""; cin >> temp;
    for (int i = 0; i < (int)temp.size() - 1; ++i) {
        s += temp[i];
        s += '#';
    }
    s += temp.back();
    int n = (int)s.size();
    vector<hash_t> h(n + 1), rev_h(n + 1), p(n + 1);
    p[0] = hash_t(1, 1);
    for (int i = 0; i < n; ++i) {
        h[i + 1] = h[i] * base + hash_t(s[i], s[i]);
        p[i + 1] = p[i] * base;
    }
    for (int i = n - 1; i >= 0; --i) {
        rev_h[i] = rev_h[i + 1] * base + hash_t(s[i], s[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = 1, r = min(i + 1, n - i) + 1, m;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (check(i, m, h, rev_h, p)) {
                l = m;
            } else {
                r = m;
            }
        }
        ans += (l + (i + 1) % 2) / 2;
    }
    cout << ans;





    return 0;
}
