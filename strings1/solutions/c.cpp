#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> p_func(string s) {
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0) {
            if (s[j] == s[i]) {
                break;
            }
            j = p[j - 1];
        }
        p[i] = j + (s[i] == s[j]);
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t; cin >> s >> t;
    s = t + '#' + s;
    vector<int> p = p_func(s);
    for (int i = 0; i < (int)s.size(); ++i) {
        if (p[i] == (int)t.size()) {
            cout << i - 2 * int(t.size()) << ' ';
        }
    }


    return 0;
}