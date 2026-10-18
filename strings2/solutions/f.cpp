#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
mt19937_64 rnd(clock());

ull mod;
struct hash_t {
    int x;
    hash_t(int v = 0) {
        x = v;
    }
    hash_t operator+(const hash_t other) const {
        if (0ll + x + other.x >= mod) return hash_t(0ll + x + other.x - mod);
        return hash_t(x + other.x);
    }
    hash_t operator-(const hash_t other) const {
        if (0ll + x - other.x < 0) return hash_t(0ll + x - other.x + mod);
        return hash_t(0ll + x - other.x);
    }
    hash_t operator*(const hash_t other) const {
        return (1ll * x * other.x % mod);
    }
    bool operator==(const hash_t other) const {
        return x == other.x;
    }
};
hash_t base;


int get(string s) {
    hash_t h = hash_t(0);
    for (auto c : s) {
        h = h * base + hash_t(c);
    }
    return h.x;
}

string rad() {
    int len = rnd() % 1000 + 1;
    string ans = "";
    for (int i = 0; i < len; ++i) {
        ans += (char)('a' + rnd() % 26);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p; cin >> p >> mod;
    base = hash_t(p);

    map<int, unordered_set<string>> mp;
    while (true) {
        string temp = rad();
        int h = get(temp);
        mp[h].insert(temp);
        if (mp[h].size() == 2) {
            for (auto i : mp[h]) {
                cout << i << '\n';
            }
            break;
        }
    }



    return 0;
}
