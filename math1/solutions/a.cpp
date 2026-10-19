#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}
