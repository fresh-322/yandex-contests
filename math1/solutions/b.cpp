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
    ll a, b, c;
    cin >> a >> b >> c;
    ll x, y;
    ll g = gcd(a, b);
    if (c % g == 0) {
        cool_gcd(a, b, x, y);
        ll x0 = x * (c / g);
        ll y0 = y * (c / g);
        ll k = 0;
        ll xmin = x0;
        while (xmin - b / g >= 0) {
            k--;
            xmin -= b / g;
        }
        while (xmin < 0) {
            k++;
            xmin += b / g;
        }
        cout << x0 + k * (b / g) << ' ' << y0 - k * (a / g);
    } else {
        cout << "Impossible";
    }
    return 0;
}
