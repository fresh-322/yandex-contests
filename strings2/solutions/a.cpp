#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
mt19937 rnd(clock());
ll mod = 1e9 + 7;

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
        if (x - other.x < 0) return hash_t(x - other.x + mod, y - other.y);
        return hash_t(x - other.x, y - other.y);
    }
    hash_t operator*(const hash_t& other) const {
        return hash_t(1ll * x * other.x % mod, y * other.y);
    }
    bool operator==(const hash_t& other) const {
        return x == other.x && y == other.y;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int temp = rnd();
    hash_t base = hash_t(temp, temp);
    string s; cin >> s;
    int q; cin >> q;
    int n = s.size();

    vector<hash_t> h(s.size() + 1), p(s.size() + 1);
    p[0] = hash_t(1, 1);
    for (int i = 0; i < n; ++i) {
        h[i + 1] = h[i] * base + hash_t(s[i] - 'a' + 1, s[i] - 'a' + 1);
        p[i + 1] = p[i] * base;
    }

    for (int i = 0; i < q; ++i) {
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2; l1--, l2--;
        if (r2 - l2 != r1 - l1) {
            cout << "No" << '\n';
            continue;
        }
        hash_t a = h[r1] - h[l1] * p[r1 - l1], b = h[r2] - h[l2] * p[r2 - l2];
        if (a == b) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }

    return 0;
}
