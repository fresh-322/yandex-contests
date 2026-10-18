#include<bits/stdc++.h>
using namespace std;

vector<int> p_to_z(vector<int> &p) {
    int n = (int)p.size();
    vector<int> z(n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        z[i - p[i] + 1] = p[i];
    }
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = max(z[i], min(z[i - l], r - i));
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    vector<int> z = p_to_z(p);
    for (auto i : z) cout << i << ' ';




    return 0;
}
