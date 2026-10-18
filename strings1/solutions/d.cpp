#include<bits/stdc++.h>
using namespace std;

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

    string t, s; cin >> t >> s;
    s = t + '#' + s + s;
    vector<int> p = p_func(s);
    bool answered = false;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (p[i] == (int)t.size() && !answered) {
            cout << i - 2 * t.size();
            answered = true;
        }
    }
    if (!answered) {
        cout << -1;
    }


    return 0;
}
