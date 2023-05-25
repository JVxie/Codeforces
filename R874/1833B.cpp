//
// Created by Jeson Vendetta Xie on 2023/5/24.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 10;

struct Data {
    int a, i;
    bool operator < (const Data &x) const {
        if (a == x.a) {
            return i < x.i;
        }
        return a < x.a;
    }
}dat[MAX_N];
int b[MAX_N], ans[MAX_N];

int main() {
    int T, n, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &dat[i].a);
            dat[i].i = i;
        }
        sort(dat + 1, dat + 1 + n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &b[i]);
        }
        sort(b + 1, b + 1 + n);
        for (int i = 1; i <= n; ++i) {
            ans[dat[i].i] = b[i];
        }
        for (int i = 1; i < n; ++i) {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[n]);
    }
    return 0;
}