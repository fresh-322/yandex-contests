#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> z_f(string s) {
    int n = s.size();
    vector<ll> z(n);
    z[0] = n;
    ll l = 0, r = 0, j;
    for (int i = 1; i < n; ++i) {
        j = 0;
        if (i < r) {
            j = min(z[i - l], r - i);
        }
        while (i + j < n && s[j] == s[i + j]) {
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

    string s; cin >> s;
    int n = s.size();
    string temp = "#" + s;
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += (n - i + 1) * (n - i + 1);
    }
    for (int i = n - 1; i >= 0; --i) {
        temp = s[i] + temp;

        vector<ll> z = z_f(temp);

        for (int j = (int)temp.size() - n; j < (int)temp.size(); ++j) {
            ans -= min(z[j], (ll)n - 1);
        }
    }
    cout << ans / 2;

    return 0;
}
