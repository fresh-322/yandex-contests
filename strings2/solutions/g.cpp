#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, int>> h;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    h.resize(2 * n * n, {-1, 0});

    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll pos = (0ll + c[i] + d[j]) % (2 * n * n);
            ll sum = 0ll + c[i] + d[j];
            if (pos < 0) pos += 2 * n * n;
            while (h[pos].first != -1 && h[pos].first != sum) {
                pos = (pos + 1) % (2 * n * n);
            }
            h[pos].first = sum;
            h[pos].second++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll sum = -(0ll + a[i] + b[j]);
            ll pos = sum % (2 * n * n);
            if (pos < 0) pos += 2 * n * n;

            while (h[pos].first != sum && h[pos].first != -1) {
                pos = (pos + 1) % (2 * n * n);
            }
            if (h[pos].first == sum) {
                ans += h[pos].second;
            }
        }
    }
    cout << ans;

    return 0;
}
