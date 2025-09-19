
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1'000'000'007;

struct BIT {
    int n;
    vector<int> bit;
    BIT() {}
    BIT(int n_): n(n_), bit(n_ + 2, 0) {}
    void reset(int n_) { n = n_; bit.assign(n_ + 2, 0); }
    void add(int i, int v) {
        for (++i; i <= n + 1; i += i & -i) {
            int x = bit[i] + v;
            if (x >= MOD) x -= MOD;
            bit[i] = x;
        }
    }
    int sum(int i) const {
        long long s = 0;
        for (++i; i > 0; i -= i & -i) s += bit[i];
        return int(s % MOD);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int m = n + 1;
        vector<vector<int>> dp(m, vector<int>(m, 0));
        vector<BIT> row(m), col(m);
        for (int i = 0; i < m; ++i) { row[i].reset(n + 1); col[i].reset(n + 1); }

        dp[0][0] = 1;
        row[0].add(0, 1);
        col[0].add(0, 1);

        for (int v : a) {
            for (int j = 0; j <= n; ++j) {
                int add = col[j].sum(v);
                if (add) {
                    int nv = dp[v][j] + add; if (nv >= MOD) nv -= MOD;
                    dp[v][j] = nv;
                    col[j].add(v, add);
                    row[v].add(j, add);
                }
            }
            for (int i = v + 1; i <= n; ++i) {
                int add = row[i].sum(v);
                if (add) {
                    int nv = dp[i][v] + add; if (nv >= MOD) nv -= MOD;
                    dp[i][v] = nv;
                    row[i].add(v, add);
                    col[v].add(i, add);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j) {
                ans += dp[i][j];
                if (ans >= MOD) ans -= MOD;
            }
        cout << ans % MOD << '\n';
    }
    return 0;
}
