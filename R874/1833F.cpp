//
// Created by Jeson Vendetta Xie on 2023/5/24.
//

#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MOD = 1e9 + 7;
const int MAX_N = 2e5 + 10;

inline int add(int a, int b) {
    return a + b > MOD ? a + b - MOD : a + b;
}

inline int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

inline int quickPow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = mul(ans, a);
        }
        b >>= 1;
        a = mul(a, a);
    }
    return ans;
}

int a[MAX_N], b[MAX_N], c[MAX_N], p[MAX_N];

void solve() {
    int n, m, k, ans, tmp;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    a[n + 1] = 0;
    k = ans = 0;
    tmp = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == a[i + 1]) {
            ++tmp;
        } else {
            b[++k] = a[i];
            c[k] = tmp;
            tmp = 1;
        }
    }
    p[0] = 1;
    for (int i = 1; i <= k; ++i) {
        p[i] = mul(p[i - 1], c[i]);
    }
    for (int i = 1; i + m - 1 <= k; ++i) {
        if (b[i + m - 1] - b[i] == m - 1) {
            ans = add(ans, mul(p[i + m - 1], quickPow(p[i - 1], MOD - 2)));
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
//    printf("111");
    while (T--) {
        solve();
    }
    return 0;
}