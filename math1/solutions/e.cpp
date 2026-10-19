#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll cool_gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll xp, yp;
    ll g = cool_gcd(b % a, a, xp, yp);
    x = yp - xp * (b / a);
    y = xp;
    return g;
}

int main() {
    ll a, m;
    cin >> a >> m;
    ll b = m;
    ll x, y;
    ll g = gcd(a, b);
    if (a != 0 && m > 1 && g == 1) {
        cool_gcd(a, b, x, y);

        cout << (x % m + m) % m;
    } else {
        cout << -1;
    }
    return 0;
}
