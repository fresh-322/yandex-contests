#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> p(s.size());
    p[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0) {
            if (s[j] == s[i]) {
                break;
            }
            j = p[j - 1];
        }
        if (s[j] == s[i]) {
            p[i] = j + 1;
        } else {
            p[i] = j;
        }
    }
    for (auto i : p)
        cout << i << ' ';
    return 0;
}
