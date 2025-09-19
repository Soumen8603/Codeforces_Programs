
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long MOD = 1000000007LL;
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<vector<long long>> prev(n + 1, vector<long long>(n + 1, 0LL));
        prev[0][0] = 1LL;
        for (int i = 0; i < n; ++i) {
            vector<vector<long long>> curr(n + 1, vector<long long>(n + 1, 0LL));
            int z = a[i + 1];
            for (int ss = 0; ss <= n; ++ss) {
                for (int mm = 0; mm <= n; ++mm) {
                    if (prev[ss][mm] == 0) continue;
                    // skip
                    curr[ss][mm] = (curr[ss][mm] + prev[ss][mm]) % MOD;
                    // add
                    if (mm <= z) {
                        int news = max(ss, z);
                        int newm = mm;
                        if (ss > z) {
                            newm = max(mm, z);
                        }
                        curr[news][newm] = (curr[news][newm] + prev[ss][mm]) % MOD;
                    }
                }
            }
            prev = std::move(curr);
        }
        long long ans = 0;
        for (int ss = 0; ss <= n; ++ss) {
            for (int mm = 0; mm <= n; ++mm) {
                ans = (ans + prev[ss][mm]) % MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
