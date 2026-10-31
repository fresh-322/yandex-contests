#include <bits/stdc++.h>
using namespace std;

bool ask(int x) {
    cout << "? " << x << endl;
    int l;
    cin >> l;
    cout << "? " << x + 1 << endl;
    int r;
    cin >> r;
    if ((x & 1) == 0) {
        return l != r;
    } else {
        return l == r;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int l = 0, r = n, m;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (ask(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    int ans;
    cout << "? " << r << endl;
    cin >> ans;
    cout << "! " << ans << endl;

    return 0;
}
