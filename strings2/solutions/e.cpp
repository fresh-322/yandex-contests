#include<bits/stdc++.h>
using namespace std;

vector<string> trans = {"Aa", "BB"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k; cin >> k;
    for (int i = 0; i < k; ++i) {
        for (int mask = 1; mask < (1 << 11); mask = mask << 1) {
            cout << trans[(bool)(i & mask)];
        }
        cout << '\n';
    }

    return 0;
}
