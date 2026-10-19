#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, r;
    cin >> l >> r;
    vector<bool> is_prime(r + 1, 1);
    is_prime[1] = 0;
    for (int i = 2; i <= r; ++i) {
        for (int j = 2 * i; j <= r; j += i) {
            is_prime[j] = false;
        }
    }
    for (int i = l; i <= r; ++i) {
        if (is_prime[i]) {
            cout << i << ' ';
        }
    }
}
