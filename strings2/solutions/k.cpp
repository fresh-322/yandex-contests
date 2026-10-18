#include<bits/stdc++.h>
using namespace std;

vector<int> z_f(deque<int>& a) {
    vector<int> z(a.size());
    z[0] = (int)a.size();
    int l = 0, r = 0;
    for (int i = 1; i < (int)a.size(); ++i) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < (int)a.size() && a[z[i]] == a[i + z[i]]) {
            z[i]++;
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
    string s, t; cin >> s >> t;
    t = t + t;
    pair<int, int> ans = {-1, -1};
    deque<int> a(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; ++i) {
        if ((t[i] - t[i + 1] + 26) % 26 < (t[i + 1] - t[i] + 26) % 26) {
            a[i] = -((t[i] - t[i + 1] + 26) % 26);
        } else {
            a[i] = (t[i + 1] - t[i] + 26) % 26;
        }
    }
    a.push_front(27);
    for (int i = n - 2; i >= 0; --i) {
        if ((s[i] - s[i + 1] + 26) % 26 < (s[i + 1] - s[i] + 26) % 26) {
            a.push_front(-((s[i] - s[i + 1] + 26) % 26));
        } else {
            a.push_front((s[i + 1] - s[i] + 26) % 26);
        }
    }
    vector<int> z = z_f(a);

    for (int i = n; i < (int)z.size(); ++i) {
        if (z[i] == n - 1) {
            ans.first = i - n;
            break;
        }
    }
    if (ans.first == -1) {
        cout << "Impossible";
        return 0;
    }
    string true_t = "";
    for (int i = ans.first; i < ans.first + n; ++i) {
        true_t += t[i];
    }

    int check;
    if ((s[0] - true_t[0] + 26) % 26 < (true_t[0] - s[0] + 26) % 26) {
        check = -(s[0] - true_t[0] + 26) % 26;
    } else {
        check = ((true_t[0] - s[0] + 26) % 26);
    }
    for (int i = 1; i < n - 1; ++i) {
        int temp;
        if ((s[i] - true_t[i] + 26) % 26 < (true_t[i] - s[i] + 26) % 26) {
            temp = -(s[i] - true_t[i] + 26) % 26;
        } else {
            temp = ((true_t[i] - s[i] + 26) % 26);
        }
        if (temp != check) {
            cout << "Impossible";
            return 0;
        }
    }
    cout << "Success" << '\n' << ans.first << ' ' << check;



    return 0;
}
