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
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        ll q, w, n, m;
        cin >> q >> w >> n >> m;
        ll a = n, b = m, c = w - q;
        ll g = gcd(a, b);
        ll x, y;
        if (c % g == 0) {
            cool_gcd(a, b, x, y);
            ll x0 = x * (c / g);
            ll xmin = x0;
            while ((xmin - b / g) * n + q >= 0) {
                xmin -= b / g;
            }
            while (xmin * n + q < 0) {
                xmin += b / g;
            }
            cout << "YES " << (xmin)*n + q << ' ' << n * m / gcd(n, m) << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
