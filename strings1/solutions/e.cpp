#include<bits/stdc++.h>
using namespace std;

void build(string &s) {
    int n = s.size();
    s += '#';
    for (int i = n - 1; i >= 0; --i) {
        s += s[i];
    }
}

vector<int> z_func(string s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        int j = 0;
        if (i < r) {
            j = min(r - i, z[i - l]);
        }
        while (i + j < n && s[j] == s[i + j]) {
            j++;
        }
        z[i] = j;
        if (i + j > r) {
            l = i;
            r = i + j;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;
    build(s);
    vector<int> temp = z_func(s);
    vector<int> ans(n);

    for (int i = n + 1; i < (int)s.size(); ++i) {
        ans[(int)s.size() - 1 - i] = temp[i];
    }
    for (auto i : ans) cout << i << ' ';


    return 0;
}