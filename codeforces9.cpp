#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(k);
        for (int i = 0; i < k; ++i) {
            cin >> b[i];
        }
        sort(a.rbegin(), a.rend());
        sort(b.begin(), b.end());
        long long total = 0;
        for (auto x : a) total += x;
        long long saved = 0;
        int avail = 0;
        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            long long qi = a[i];
            int maxx = avail + 1;
            if (ptr < k && b[ptr] <= maxx) {
                saved += qi;
                avail -= (b[ptr] - 1);
                ++ptr;
            } else {
                ++avail;
            }
        }
        long long cost = total - saved;
        cout << cost << '\n';
    }
    return 0;
}