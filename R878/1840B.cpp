//
// Created by JVxie on 2023/6/6.
//

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    long long p, sum;
    scanf("%d %d", &n, &k);
    for (p = 1, sum = 0; p <= k && sum <= n; ++p) {
        sum += 1 << (p - 1);
    }
    if (sum > n) {
        sum -= 1 << (p - 1);
        --p;
    }
    if (p <= k) {
        printf("%d\n", n + 1);
    } else {
        printf("%lld\n", sum + 1);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}