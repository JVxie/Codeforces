//
// Created by JVxie on 2023/6/6.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 10;

int a[MAX_N];

void solve() {
    int n, k, q;
    long long ans = 0;
    scanf("%d %d %d", &n, &k, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int l, r;
    for (l = 1; l <= n;) {
        for (r = l; r <= n; ++r) {
            if (a[r] > q) {
                break;
            }
        }
        if (r - l + 1 >= k) {
            long long p = r - l + 1;
            ans += (p - k + 1) * (p - k) / 2;
        }
        l = r + 1;
    }
    printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}