//
// Created by Jeson Vendetta Xie on 2023/5/29.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 10;

int a[MAX_N], b[MAX_N], c[MAX_N << 1], d[MAX_N << 1];

void solve() {
    int n, now = 0, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= (n << 1); ++i) {
        c[i] = d[i] = 0;
    }
    for (int i = 1, cnt = 1; i <= n; ++i) {
        if (a[i] != a[i - 1]) {
            cnt = 1;
        } else {
            ++cnt;
        }
        c[a[i]] = max(c[a[i]], cnt);
    }
    for (int i = 1, cnt = 1; i <= n; ++i) {
        if (b[i] != b[i - 1]) {
            cnt = 1;
        } else {
            ++cnt;
        }
        d[b[i]] = max(d[b[i]], cnt);
    }
    for (int i = 1; i <= (n << 1); ++i) {
        ans = max(ans, c[i] + d[i]);
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}