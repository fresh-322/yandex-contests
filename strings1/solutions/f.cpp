#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int max_power = 31;

struct node {
    int term = 0;
    node* link[2];
};
node* root = new node();
void add(node* v, int x) {
    for (int i = max_power; i >= 0; --i) {
        bool bit = bool(x & (1 << i));
        if (v->link[bit] == nullptr) {
            v->link[bit] = new node();
        }
        v = v->link[bit];
        v->term++;
    }
}
void del(node* v, int x) {
    for (int i = max_power; i >= 0; --i) {
        bool bit = bool(x & (1 << i));
        v = v->link[bit];
        v->term--;
    }
}
int ans(node* v, int x) {
    int cnt = 0;
    for (int i = max_power; i >= 0; --i) {
        bool bit = bool(x & (1 << i));
        if (v->link[!bit] != nullptr && v->link[!bit]->term != 0) {
            v = v->link[!bit];
            cnt += 1 << i;
        } else {
            v = v->link[bit];
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    add(root, 0);
    for (int i = 0; i < q; ++i) {
        char act; cin >> act;
        if (act == '+') {
            int x; cin >> x;
            add(root, x);
        }
        if (act == '-') {
            int x; cin >> x;
            del(root, x);
        }
        if (act == '?') {
            int x; cin >> x;
            cout << ans(root, x) << '\n';
        }
    }

    return 0;
}
