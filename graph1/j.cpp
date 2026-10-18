#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
deque<int> ans;
vector<int> need;
vector<int> have;
vector<int> where_need;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    g.resize(n);
    need.resize(n);
    have.resize(n, 0);
    where_need.resize(n, 0);
    priority_queue<int> pq;

    for (int i = 0; i < n; ++i) {
        int k; cin >> k;

        for (int j = 0; j < k; ++j) {
            int v; cin >> v; v--;
            g[i].push_back(v);
            need[v]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (need[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int v = pq.top();
        pq.pop();
        ans.push_front(v);
        for (auto to : g[v]) {
            need[to]--;
            if (0 == need[to]) {
                pq.push(to);
            }
        }
    }
    for (auto i : ans) {
        cout << i + 1 << ' ';
    }
    return 0;
}
