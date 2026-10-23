#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    ll m1, m2, m3; cin >> m1 >> m2 >> m3;
    for (int i = 0; i < t; ++i) {
        ll a1, b1, c1; cin >> a1 >> b1 >> c1;
        ll a2, b2, c2; cin >> a2 >> b2 >> c2;
        a2 = a2 - a1;
        if (a2 <= 0) a2 += m1;
        b2 = b1 - b2;
        if (b2 <= 0) b2 += m2;
        c2 = c2 - c1;
        if (c2 <= 0) c2 += m3;

        if (abs(b2 - a2) % gcd(m1, m2) == 0 && abs(c2 - b2) % gcd(m2, m3) == 0 && abs(c2 - a2) % gcd(m1, m3) == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}