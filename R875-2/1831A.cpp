//
// Created by Jeson Vendetta Xie on 2023/5/29.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 110;

int a[MAX_N], b[MAX_N];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        b[i] = n - a[i] + 1;
        printf("%d ", b[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}