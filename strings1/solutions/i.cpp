#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> z_f(vector<ll> a) {
    vector<ll> z(a.size());
    ll l = 0, r = 0;
    z[0] = 0;
    for (int i = 1; i < (int)a.size(); ++i) {
        int j = 0;
        if (i < r) {
            j = min(z[i - l], r - i);
        }
        while (i + j < (int)a.size() && a[j] == a[i + j]) {
            j++;
        }
        z[i] = j;
        if (i + j > r) {
            r = i + j;
            l = i;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    if (k == 1) {
        for (int i = 1; i < n + 1; ++i) {
            cout << i << ' ';
        }
        return 0;
    }
    vector<ll> a(n - 1), l(k - 1);
    ll q; cin >> q;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
        a[i] = a[i] - q;
        q = a[i] + q;
    }
    cin >> q;
    for (int i = 0; i < k - 1; ++i) {
        cin >> l[i];
        l[i] = l[i] - q;
        q = l[i] + q;
    }

    l.push_back(-1);
    for (auto i : a) {
        l.push_back(i);
    }
    vector<ll> z = z_f(l);
    for (int i = k; i < (int)z.size(); ++i) {
        if (z[i] == k - 1) {
            cout << i - k + 1 << ' ';
        }
    }



    return 0;
}