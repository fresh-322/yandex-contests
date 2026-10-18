#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    cout << "printed" << '\n';
    vector<int> z((int)s.size());
    int l = 0, r = 0;
    z[0] = s.size();
    for (int i = 1; i < (int)s.size(); ++i) {
        int j = 0;
        if (i < r) {
            j = min(r - i, z[i - l]);
        }
        while (i + j < (int)s.size() && s[j] == s[i + j]) {
            j++;
        }
        z[i] = j;
        if (i + j > r) {
            l = i;
            r = i + j;
        }
    }
    for (auto i : z)
        cout << i << ' ';

    return 0;
}
