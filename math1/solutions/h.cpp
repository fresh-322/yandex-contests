#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> s(5e6 + 1, 0);
    vector<ll> pref(5e6 + 1, 0);
    for (int i = 1; i <= 5e6; ++i) {
        for (int j = i; j <= 5e6; j += i) {
            s[j] += i;
        }
    }
    for (int i = 1; i <= 5e6; ++i) {
        pref[i] = pref[i - 1] + s[i];
    }


    int l, r;
    while (cin >> l >> r) {
        cout << pref[r] - pref[l - 1] << '\n';
    }
    return 0;
}