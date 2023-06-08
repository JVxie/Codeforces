//
// Created by JVxie on 2023/6/6.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 10;

int a[MAX_N];

bool check(int n, int x) {
    int cnt = 0, l = 0, r = 0;
    for (int i = 1; i <= n; ++i) {
        int tmpL = max(1, a[i] - x), tmpR = min((int)1e9, a[i] + x);
        if (tmpL > r) {
            ++cnt;
            l = tmpL, r = tmpR;
        } else {
            l = max(tmpL, l);
            r = min(tmpR, r);
        }
    }
    return cnt <= 3;
}

void solve() {
    int n, l, r, mid;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    l = 0, r = 1e9;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(n, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", r);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}