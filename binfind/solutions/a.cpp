
#include <bits/stdc++.h>
using namespace std;

int ask(int x) {
    cout << x << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int l = 1, r = n + 1, m = 0;
    while (r - l > 1) {
        m = (l + r) / 2;
        int ans = ask(m);
        if (ans == 1) {
            l = m;
        } else if (ans == -1) {
            r = m;
        }
        if (ans == 0) {
            l = m;
            return 0;
        }
    }
    ask(l);
    return 0;
}
