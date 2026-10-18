#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
    bool term = 0;
    int cnt = 0;
    node* link[26];
};

void add(node* v, string s) {
    for (char ch : s) {
        if (v->link[ch - 'a'] == nullptr){
            v->link[ch - 'a'] = new node();
        }
        v = v->link[ch - 'a'];
        v->cnt++;
    }
    v->term = true;
}
node* root = new node();

string ans(node* v, int k) {
    string ans = "";
    while (k != 0) {
        for (int ch = 0; ch < 26; ++ch) {
            if (v->link[ch] == nullptr) continue;
            if (v->link[ch]->cnt < k) {
                k -= v->link[ch]->cnt;
            } else {
                ans += ('a' + ch);
                if (v->link[ch]->term) {
                    k -= 1;
                    if (k == 0) {
                        break;
                    }
                }
                v = v->link[ch];

                break;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int act; cin >> act;
        if (act == 1) {
            string s; cin >> s;
            add(root, s);
        } else {
            int k; cin >> k;
            cout << ans(root, k) << '\n';
        }
    }



    return 0;
}
