//
// Created by Jeson Vendetta Xie on 2023/5/24.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2010;

int a[MAX_N];

void solve() {
    int n, l, r, maxX = 0, maxI = 1;
    scanf("%d", &n);
    for (int i = 0; i <= n + 5; ++i) {
        a[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (i > 1 && a[i] > maxX) {
            maxX = a[i];
            maxI = i;
        }
    }
    // 确定l r位置
    if (maxI == n) {
        l = r = n;
    } else {
        l = maxI - 2;
        r = maxI - 1;
    }
    while (l > 1 && a[l] >= a[1]) {
        --l;
    }
    if (l >= 1 && a[l] < a[1]) {
        ++l;
    }
    if (l < 1) {
        l = 1;
    }
    if (l > r) {
        l = r;
    }
//    printf("----%d %d\n", l, r);
    for (int i = r + 1; i <= n; ++i) {
        printf("%d ", a[i]);
    }
    for (int i = r; i >= l; --i) {
        printf("%d ", a[i]);
    }
    for (int i = 1; i < l; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}