//
// Created by JVxie on 2023/5/26.
//

#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX_N = 3e5 + 10;

struct Data {
    int a, i;
}dat[MAX_N];

bool cmp(const Data &x, const Data &y) {
    if (x.a != y.a) {
        return x.a < y.a;
    } else {
        return x.i < y.i;
    }
}

bool cmp2(const Data &x, const Data &y) {
    if (x.i != y.i) {
        return x.i < y.i;
    } else {
        return x.a < y.a;
    }
}
ll sum[MAX_N];

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &dat[i].a);
        dat[i].i = i;
    }
    sort(dat + 1, dat + 1 + n, cmp);
    sort(dat + 1, dat + 1 + k, cmp2);
    for (int i = 1; i <= k; ++i) {
        sum[i] = sum[i - 1] + dat[i].a;
    }
    ll ans = 1LL << 62;
    for (int i = 1; i <= k; ++i) {
        ll tmp1 = sum[i], tmp2 = sum[k] - sum[i];
        ans = min(max(tmp1, tmp2), ans);
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